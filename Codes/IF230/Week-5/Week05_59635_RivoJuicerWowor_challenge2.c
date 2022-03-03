#include <ctype.h>
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum { FALSE, TRUE } bool;

// Create a variable to count the amount of node inside our linked list

int nodeCount = 0;

// Create two struct that will contain our data and pointers.
typedef struct Request {
  char name[50];
  int nim;
  char major[25];
  char angkatan[5];
  char gedung;
  int noRuang;
  bool approve;
} Request;

typedef struct Node {
  Request data;

  struct Node *next, *prev;
} Node;

int menu() {
  // This function will display our main menu and return the desirable menu
  // choice by user.
  int menu;
  printf("=========================\n");
  printf(" Menu Peminjaman Ruangan\n");
  printf("=========================\n");
  printf("1. Pinjam ruangan\n"
         "2. List ruangan yang dipinjam\n"
         "3. Hapus list ruangan yang dipinjam (Clear All)\n"
         "4. Menyetujui Ruangan\n"
         "5. Batalkan peminjaman ruangan\n"
         "6. Urutkan data berdasarkan NIM\n"
         "7. Exit\n");
  printf("Input : ");
  scanf("%i%*c", &menu);
  return menu;
}

int checkDuplicate(Node *head, Node *tail, Request newData) {
  // This function will check any duplicates that are in our linked list. If it
  // has any, it will return 1 for error.
  for (int i = 0; i < nodeCount; i++) {
    Request currData = head->data;
    if ((currData.gedung == newData.gedung) &&
        (currData.noRuang == newData.noRuang)) {
      return 1;
    }
    head = head->next;
  }
  return 0;
}

Request newReq() {
  // This function will make a new request based on user's input
  // and the request would be returned to the main function

  printf("\n");
  Request data;
  char nim[25];
  printf("===============================\n");
  printf(" Input Data Peminjaman Ruangan \n");
  printf("===============================\n");
  printf("%-15s : ", "Nama");
  scanf("%[^\n]%*c", data.name);
  printf("%-15s : ", "NIM");
  scanf("%[^\n]%*c", nim);
  printf("%-15s : ", "Program Studi");
  scanf("%[^\n]%*c", data.major);
  printf("%-15s : ", "Angkatan");
  scanf("%[^\n]%*c", data.angkatan);
  printf("%-15s : ", "Gedung (A-D)");
  scanf("%c%*c", &data.gedung);
  printf("%-15s : ", "Nomor Ruangan");
  scanf("%i%*c", &data.noRuang);
  data.nim = atoi(nim);
  data.approve = FALSE;

  printf("\n");
  return data;
}

void addNodeCircular(Request data, Node **head, Node **tail) {
  // This function will make a new node based on the request data
  // passed on the arguments.
  // The new node would be made at the end of our linked list.
  Node *node = (Node *)malloc(sizeof(Node));
  node->data = data;
  if (*head == NULL) {
    *head = *tail = node;
    (*head)->next = (*tail)->prev = node;
  } else {
    node->next = *head;
    node->prev = *tail;
    (*head)->prev = node;
    (*tail)->next = node;
    *tail = node;
  }
  nodeCount++;
}

void removeNode(Node **curr, Node **head, Node **tail) {
  if (*curr == *head && *curr == *tail) {
    free(*curr);
    *curr = *head = *tail = NULL;
    return;
  }
  Node *temp = *curr;
  *curr = (*curr)->next;
  if (temp == *head)
    *head = temp->next;
  if (temp == *tail)
    *tail = temp->prev;

  if (temp->next != NULL)
    temp->next->prev = temp->prev;
  if (temp->prev != NULL)
    temp->prev->next = temp->next;

  temp->next = temp->prev = NULL;
  free(temp);
}

void clearReq(Node **head, Node **tail) {
  // This function has similar functionalities with printReqAll()
  // where it would loop over every node until the end of our linked list.
  // But the difference is it will remove the node along when looping
  // So it will clear the entire linked list from memory.
  if (*head == NULL) {
    printf("\nData masih kosong!\n\n");
    return;
  }

  Node *temp = *head;
  while (temp != NULL) {
    removeNode(&temp, head, tail);
    if (temp == NULL)
      break;
    temp = temp->next;
  }
}

int largerDigit(Node *start) {
  int temp = 0, digit = 0;
  Node *p = start;
  do {
    Request data = p->data;
    if (data.nim > temp) {
      temp = data.nim;
    }
    p = p->next;
  } while (p != start);
  while (temp != 0) {
    digit++;
    temp /= 10;
  }
  return digit;
}

int digitFinder(int data, int iterator) {
  int term, count;
  for (count = 1; count <= iterator; count++) {
    term = data % 10;
    data = data / 10;
  }
  return term;
}

void radixSort(Node **head, Node **tail) {
  int count, k, digit, maxIteration;

  char choice;
  printf("Sort ascending (a) atau descending (d)?: ");
  scanf("%c", &choice);
  choice = tolower(choice);
  if (!(choice == 'a' || choice == 'd')) {
    printf("Menu tidak ditemukan!\n");
    return;
  }

  Node *bucketHead[10] = {0}, *bucketTail[10] = {0}, *temp;
  maxIteration = largerDigit(*head);
  for (k = 1; k <= maxIteration; k++) {
    // for (count = 0; count <= 9; count++) {
    //   bucketHead[count] = NULL;
    //   bucketTail[count] = NULL;
    // }
    temp = *head;
    do {
      digit = digitFinder(temp->data.nim, k);
      addNodeCircular(temp->data, &bucketHead[digit], &bucketTail[digit]);
      temp = temp->next;
    } while (temp != *head);
    clearReq(head, tail);
    for (int i = choice == 'a' ? 0 : 9;
         (choice == 'a' && i <= 9) || (choice == 'd' && i >= 0);
         choice == 'a' ? i++ : i--) {
      Node *p = bucketHead[i];
      if (p == NULL)
        continue;
      do {
        addNodeCircular(p->data, head, tail);
        p = p->next;
      } while (p != bucketHead[i]);
      clearReq(&bucketHead[i], &bucketTail[i]);
    }
  }
  printf("\nData berhasil di sort!\n");
}

void printReq(Request data) {
  printf("%-9s : %s\n", "Nama", data.name);
  printf("%-9s : %011i\n", "NIM", data.nim);
  printf("%-9s : %s\n", "Prodi", data.major);
  printf("%-9s : %s\n", "Angkatan", data.angkatan);
  printf("%-9s : %c%i\n", "Ruangan", data.gedung, data.noRuang);
  printf("%-9s : %s\n", "Status", data.approve ? "Approved" : "Unapproved");
}

void printReqAll(Node *head, Node *tail) {
  // This function would print every element of our linked list.
  // It will loop over every node until the end of our linked list.
  int count = 0;
  Node *temp = head;
  if (head == NULL) {
    printf("\nData kosong!\n");
    return;
  }
  printf("-----------------------------------\n");
  do {
    Request data = temp->data;
    printf("Data ke-%i\n", ++count);
    printReq(data);
    temp = temp->next;
    printf("-----------------------------------\n\n");
  } while (temp != head);
}

void reqApproval(Node **head, Node **tail) {
  // This function behaves almost like the printReqAll function
  // But the difference is this function have counter on what
  // index the current node, with the length. And have the ability
  // to change the approval status.
  Node *curr = *head;
  if (curr == NULL) {
    printf("\nData kosong!\n");
    return;
  }
  bool keepGoing = TRUE;
  int count = 0, menu;
  while (keepGoing) {
    Request data = curr->data;
    if (curr == *head)
      count = 1;
    if (curr == *tail)
      count = nodeCount;
    printf("\n");
    printf("=================================\n"
           "       Penyetujuan Ruangan       \n"
           "=================================\n");
    printf("%-9s : %i/%i\n", "Nomor", count, nodeCount);
    printReq(data);
    printf("Menu :\n"
           "1. Next\n"
           "2. Prev\n"
           "3. Approve\n"
           "4. Exit\n"
           "Pilihan : ");
    scanf("%i", &menu);
    switch (menu) {
    case 1:
      curr = curr->next;
      count++;
      break;
    case 2:
      curr = curr->prev;
      count--;
      break;
    case 3:
      if (curr->data.approve)
        curr->data.approve = FALSE;
      else
        curr->data.approve = TRUE;
      break;
    case 4:
      return;
    default:
      printf("Menu tidak ditemukan!");
      break;
    }
  }
}

void reqDelete(Node **head, Node **tail) {
  // This function behaves almost like the printReqAll function
  // But the difference is this function have counter on what
  // index the current node, with the length. And have the ability
  // to change the approval status.
  Node *curr = *head;
  if (curr == NULL) {
    printf("\nData kosong!\n");
    return;
  }
  bool keepGoing = TRUE;
  int count = 0, menu;
  while (keepGoing) {
    Request data = curr->data;
    if (curr == *head)
      count = 1;
    if (curr == *tail)
      count = nodeCount;
    printf("\n");
    printf("=================================\n"
           "        Pembatalan Ruangan       \n"
           "=================================\n");
    printf("%-9s : %i/%i\n", "Nomor", count, nodeCount);
    printReq(data);

    printf("Menu :\n"
           "1. Next\n"
           "2. Prev\n"
           "3. Cancel\n"
           "4. Exit\n"
           "Pilihan : ");
    scanf("%i", &menu);
    switch (menu) {
    case 1:
      curr = curr->next;
      count++;
      break;
    case 2:
      curr = curr->prev;
      count--;
      break;
    case 3:
      printf("Deleting...\n\n");
      removeNode(&curr, head, tail);
      nodeCount--;
      break;
    case 4:
      return;
    default:
      printf("Menu tidak ditemukan!");
      break;
    }
  }
}

int main() {
  // This is the main function, where it's all started.

  // First we will make an empty node called `*head`.
  // This would be our head reference node in linked list
  Node *head = NULL;
  Node *tail = NULL;

  // Then it will call menu() and would get input from user
  // After that, the input would be checked in the switch case
  // finding the suitable function to call.
  bool keepGoing = TRUE;
  while (keepGoing) {
    Request data;
    switch (menu()) {
    case 1:
      data = newReq();
      if (checkDuplicate(head, tail, data)) {
        printf("\nRuangan telah dipinjam!\n"
               "Membatalkan input...\n\n");
        break;
      }
      addNodeCircular(data, &head, &tail);
      break;
    case 2:
      printReqAll(head, tail);
      break;

    case 3:
      clearReq(&head, &tail);
      printf("\nData berhasil dibersihkan!\n\n");
      break;

    case 4:
      reqApproval(&head, &tail);
      break;

    case 5:
      reqDelete(&head, &tail);
      break;

    case 6:
      radixSort(&head, &tail);
      break;

    case 7:
      keepGoing = FALSE;
      break;

    default:
      printf("\nMenu tidak valid!\n\n");
      break;
    }
  }
  printf("Terima kasih telah menggunakan aplikasi ini!\n");

  return 0;
}
