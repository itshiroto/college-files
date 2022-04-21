/*
  Nama: Rivo Juicer Wowor
  NIM: 00000059635
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 26
#define FILENAME "datamhs.txt"

typedef struct {
  char nim[100];
  char nama[100];
} Mhs;

typedef struct Node {
  Mhs data;
  struct Node *next;
} Node;

int menu() {
  printf("====================================================\n"
         "|                  Daftar Mahasiswa                |\n"
         "====================================================\n");
  printf("(1) Cari Mahasiswa (berdasarkan 3 huruf pertama)\n"
         "(2) Hapus Mahasiswa\n"
         "(3) Tambah Mahasiswa\n"
         "(0) Keluar\n");
  printf("Masukkan pilihan: ");
  int pilih;
  scanf("%d%*c", &pilih);
  return pilih;
}

int hash(char chr, int size) { return chr % size; }

void initHash(Node *hashTable[][MAXLEN][MAXLEN], int size) {
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      for (int k = 0; k < size; k++) {
        hashTable[i][j][k] = NULL;
      }
    }
  }
}

void prompt() {
  printf("\nTekan tombol apapun untuk melanjutkan...\n");
  getchar();
}

void insertNode(Node **head, Mhs data) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;

  if (*head == NULL) {
    *head = newNode;
  } else {
    Node *curr = *head;
    while (curr->next != NULL) {
      curr = curr->next;
    }
    curr->next = newNode;
  }
}

void insertHash(Node *hashTable[][MAXLEN][MAXLEN], Mhs data, int size) {
  int i = hash(data.nama[0], size);
  int j = hash(data.nama[1], size);
  int k = hash(data.nama[2], size);
  insertNode(&hashTable[i][j][k], data);
}

int loadHash(Node *hashTable[][MAXLEN][MAXLEN], int size) {
  FILE *fp = fopen(FILENAME, "r");
  if (fp == NULL) {
    printf("File tidak dapat dibuka\n");
    return 1;
  }
  Mhs data;
  while (fscanf(fp, "%[^-]-%[^\n\r]\n\r", data.nim, data.nama) != EOF) {
    insertHash(hashTable, data, size);
  }
  fclose(fp);
  return 0;
}

void saveHash(Node *hashTable[][MAXLEN][MAXLEN], int size) {
  FILE *fp = fopen(FILENAME, "w");
  if (fp == NULL) {
    printf("File tidak dapat dibuka\n");
    return;
  }
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      for (int k = 0; k < size; k++) {
        Node *curr = hashTable[i][j][k];
        while (curr != NULL) {
          fprintf(fp, "%s-%s\n", curr->data.nim, curr->data.nama);
          curr = curr->next;
        }
      }
    }
  }
  fclose(fp);
}

void printList(Node *head) {
  Node *curr = head;
  while (curr != NULL) {
    printf("%s-%s\n", curr->data.nim, curr->data.nama);
    curr = curr->next;
  }
}

// void printHash(Node *hashTable[][MAXLEN][MAXLEN], int size) {
//   for (int i = 0; i < size; i++) {
//     for (int j = 0; j < size; j++) {
//       for (int k = 0; k < size; k++) {
//         printList(hashTable[i][j][k]);
//       }
//     }
//   }
// }

Node **searchHead(Node *hashTable[][MAXLEN][MAXLEN], char *nama, int size) {
  int i = hash(nama[0], size);
  int j = hash(nama[1], size);
  int k = hash(nama[2], size);
  return &(hashTable[i][j][k]);
}

void searchMhs(Node *hashTable[][MAXLEN][MAXLEN], int size) {
  char nama[100];
  printf("----------------------------------------------------\n"
         "|                   Cari Mahasiswa                 |\n"
         "----------------------------------------------------\n");
  printf("Masukkan 3 huruf inisial nama yang ingin dicari : ");
  scanf("%3s%*c", nama);
  Node **currHead = searchHead(hashTable, nama, size);
  Node *curr;
  if (*currHead == NULL) {
    printf("Nama tidak ditemukan\n");
  } else {
    curr = *currHead;
    int count = 0;
    while (curr != NULL) {
      printf("Mahasiswa #%d\n", ++count);
      printf("Nama: %s\n", curr->data.nama);
      printf("NIM: %s\n", curr->data.nim);
      printf("-------------------------------------------\n");
      curr = curr->next;
    }
  }
}

void addMhs(Node *hashTable[][MAXLEN][MAXLEN], int size) {
  Mhs data;
  printf("----------------------------------------------------\n"
         "|              Tambah Mahasiswa Baru               |\n"
         "----------------------------------------------------\n");
  printf("Masukkan nama: ");
  scanf("%[^\n]%*c", data.nama);
  printf("Masukkan NIM: ");
  scanf("%s%*c", data.nim);
  insertHash(hashTable, data, size);
  printf("Mahasiswa berhasil ditambahkan!\n");
}

int removeMhs(Node *hashTable[][MAXLEN][MAXLEN], int size) {
  char nama[100];
  printf("----------------------------------------------------\n"
         "|                   Hapus Mahasiswa                |\n"
         "----------------------------------------------------\n");
  printf("Masukkan nama: ");
  scanf("%[^\n]%*c", nama);
  Node **head = searchHead(hashTable, nama, size);
  if (*head == NULL) {
    printf("Nama tidak ditemukan\n");
    return 1;
  }
  Node *curr = *head;
  Node *prev = NULL;
  while (curr != NULL) {
    if (strcmp(curr->data.nama, nama) == 0) {
      if (prev == NULL) {
        *head = curr->next;
      } else {
        prev->next = curr->next;
      }
      free(curr);
      printf("Mahasiswa berhasil dihapus!\n");
      break;
    }
    prev = curr;
    curr = curr->next;
  }
  return 0;
}

int main() {
  Node *hashDB[MAXLEN][MAXLEN][MAXLEN];
  initHash(hashDB, MAXLEN);
  if (loadHash(hashDB, MAXLEN) == 1) {
    return 1;
  };
  bool keepRunning = true;
  while (keepRunning) {
    switch (menu()) {
    case 1:
      searchMhs(hashDB, MAXLEN);
      prompt();
      break;
    case 2:
      if (removeMhs(hashDB, MAXLEN) == 0)
        saveHash(hashDB, MAXLEN);
      prompt();
      break;
    case 3:
      addMhs(hashDB, MAXLEN);
      saveHash(hashDB, MAXLEN);
      prompt();
      break;
    case 0:
      keepRunning = false;
      break;
    default:
      printf("Pilihan tidak tersedia\n");
    }
  }
  return 0;
}