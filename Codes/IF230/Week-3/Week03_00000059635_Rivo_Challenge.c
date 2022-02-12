#include <malloc.h>
#include <stdio.h>
#include <string.h>

typedef struct Request {
  char name[50];
  char nim[25];
  char major[25];
  char angkatan[5];
  char gedung;
  char noRuang[5];

  struct Request *next;
} Request;

int menu() {
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

void newReq(Request **head) {
  Request *node = (Request *)malloc(sizeof(Request));
  printf("===============================\n");
  printf(" Input Data Peminjaman Ruangan \n");
  printf("===============================\n");
  printf("%-15s : ", "Nama");
  scanf("%[^\n]%*c", node->name);
  printf("%-15s : ", "NIM");
  scanf("%[^\n]%*c", node->nim);
  printf("%-15s : ", "Program Studi");
  scanf("%[^\n]%*c", node->major);
  printf("%-15s : ", "Angkatan");
  scanf("%[^\n]%*c", node->angkatan);
  printf("%-15s : ", "Gedung (A-D)");
  scanf("%c%*c", &node->gedung);
  printf("%-15s : ", "Nomor Ruangan");
  scanf("%[^\n]%*c", node->noRuang);
  if (*head == NULL) {
    *head = node;
  } else {
    Request *curr = *head;
    while (node->next != NULL) {
      curr = curr->next;
    }
    curr->next = node;
  }
}

void printReq(Request *head) {
  int count = 0;
  printf("-----------------------------------\n");
  while (head != NULL) {
    printf("Data ke-%i\n", ++count);
    printf("%-9s : %s\n", "Nama", head->name);
    printf("%-9s : %s\n", "NIM", head->nim);
    printf("%-9s : %s\n", "Prodi", head->major);
    printf("%-9s : %s\n", "Angkatan", head->angkatan);
    printf("%-9s : %c%s\n", "Ruangan", head->gedung, head->noRuang);
    printf("%-9s : %s\n", "Status", "Unapproved");
    head = head->next;
    printf("-----------------------------------\n");
  }
}

int main() {
  Request *head;

  while (1) {
    switch (menu()) {
    case 1:
      newReq(&head);
      break;
    case 2:
      printReq(head);
      break;

    case 3:
      // TODO
      break;

    case 4:
      // TODO
      return 0;

    default:
      // TODO
      break;
    }
  }
}
