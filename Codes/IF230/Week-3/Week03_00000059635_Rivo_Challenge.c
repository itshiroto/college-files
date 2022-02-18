#include <malloc.h>
#include <stdio.h>
#include <string.h>

// Create two struct that will contain our data and pointers.

typedef struct Request {
  char name[50];
  char nim[25];
  char major[25];
  char angkatan[5];
  char gedung;
  int noRuang;
} Request;

typedef struct Node {
  Request data;

  struct Node *next;
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
         "4. Exit\n");
  printf("Input : ");
  scanf("%i%*c", &menu);
  return menu;
}

int checkDuplicate(Node *head, Request newData) {
  // This function will check any duplicates that are in our linked list. If it
  // has any, it will return 1 for error.
  while (head != NULL) {
    Request currData = head->data;
    if ((currData.gedung == newData.gedung) &&
        (currData.noRuang == newData.noRuang)) {
      return 1;
    }
    head = head->next;
  }
  return 0;
}

void newReq(Node **head) {
  // This function will make a new node based on user's input
  // Then the new node would be added on the end of our linked list
  // But the node would be checked with the existing linked list if there's any
  // duplicates withing the list.

  printf("\n");
  Request data;
  Node *node = (Node *)malloc(sizeof(Node));
  printf("===============================\n");
  printf(" Input Data Peminjaman Ruangan \n");
  printf("===============================\n");
  printf("%-15s : ", "Nama");
  scanf("%[^\n]%*c", data.name);
  printf("%-15s : ", "NIM");
  scanf("%[^\n]%*c", data.nim);
  printf("%-15s : ", "Program Studi");
  scanf("%[^\n]%*c", data.major);
  printf("%-15s : ", "Angkatan");
  scanf("%[^\n]%*c", data.angkatan);
  printf("%-15s : ", "Gedung (A-D)");
  scanf("%c%*c", &data.gedung);
  printf("%-15s : ", "Nomor Ruangan");
  scanf("%i%*c", &data.noRuang);

  node->data = data;

  if (*head == NULL) {
    *head = node;
  } else {
    Node *curr = *head;
    if (checkDuplicate(*head, data)) {
      printf("\nRuangan telah dipinjam!\n"
             "Membatalkan input...\n\n");
      return;
    }
    while (curr->next != NULL) {
      curr = curr->next;
    }
    curr->next = node;
  }
  printf("\n");
}

void printReq(Node *head) {
  // This function would print every element of our linked list.
  // It will loop over every node until the end of our linked list.
  int count = 0;
  if (head == NULL) {
    printf("\nData kosong!\n");
    return;
  }
  printf("-----------------------------------\n");
  while (head != NULL) {
    Request data = head->data;
    printf("Data ke-%i\n", ++count);
    printf("%-9s : %s\n", "Nama", data.name);
    printf("%-9s : %s\n", "NIM", data.nim);
    printf("%-9s : %s\n", "Prodi", data.major);
    printf("%-9s : %s\n", "Angkatan", data.angkatan);
    printf("%-9s : %c%i\n", "Ruangan", data.gedung, data.noRuang);
    printf("%-9s : %s\n", "Status", "Unapproved");
    head = head->next;
    printf("-----------------------------------\n\n");
  }
}

void clearReq(Node **head) {
  // This function has similar functionalities with printReq()
  // where it would loop over every node until the end of our linked list.
  // But the difference is it will remove the node along when looping
  // So it will clear the entire linked list from memory.
  if (*head == NULL) {
    printf("\nData masih kosong!\n\n");
    return;
  }

  Node *temp = (Node *)malloc(sizeof(Node));
  while (*head != NULL) {
    temp = *head;
    *head = temp->next;
    temp->next = NULL;
    free(temp);
  }
  printf("\nData berhasil dibersihkan!\n\n");
}

int main() {
  // This is the main function, where it's all started.

  // First we will make an empty node called `*head`.
  // This would be our head reference node in linked list
  Node *head = NULL;

  // Then it will call menu() and would get input from user
  // After that, the input would be checked in the switch case
  // finding the suitable function to call.
  while (1) {
    switch (menu()) {
    case 1:
      newReq(&head);
      break;
    case 2:
      printReq(head);
      break;

    case 3:
      clearReq(&head);
      break;

    case 4:
      printf("Terima kasih telah mengguakan program ini!\n\n");
      return 0;

    default:
      printf("\nMenu tidak valid!\n\n");
      break;
    }
  }
}
