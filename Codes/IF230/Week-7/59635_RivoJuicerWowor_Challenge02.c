#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Kegiatan {
  int id;
  char nama[50];
  char bidang[100];
  char jenis[50];
} Kegiatan;

Kegiatan DB[50];
int DB_SIZE;

void readFile(Kegiatan DB[], int *size) {
  FILE *data = fopen("KegiatanUMN.txt", "r");
  if (data == NULL) {
    printf("Data tidak ditemukan.\n");
    return;
  }
  int i = 0;
  while (!(feof(data))) {
    Kegiatan input;
    fscanf(data, "%d#%[^#]#%[^#]#%[^\n\r]\n", &input.id, input.nama,
           input.bidang, input.jenis);
    DB[i] = input;
    i++;
  }
  *size = i;
  fclose(data);
}

void writeFile(Kegiatan DB[], int size) {
  FILE *data = fopen("KegiatanUMN.txt", "w");
  for (int i = 0; i < size; i++) {
    Kegiatan out = DB[i];
    fprintf(data, "%d#%s#%s#%s\n", out.id, out.nama, out.bidang, out.jenis);
  }
  fclose(data);
}

void printList(Kegiatan DB[], int size) {
  printf("\n");
  printf(
      "|=====|====================================================|============"
      "==========|======================|\n");
  printf("| %-3s | %-50s | %-20s | %-20s |\n", "ID", "Nama Kegiatan", "Jenis",
         "Bidang");
  printf(
      "|=====|====================================================|============"
      "==========|======================|\n");
  for (int i = 0; i < size; i++)
    printf("| %03d | %-50s | %-20s | %-20s |\n", DB[i].id, DB[i].nama,
           DB[i].bidang, DB[i].jenis);

  printf(
      "|=====|====================================================|============"
      "==========|======================|\n");
}

int mainMenu() {
  int menu;
  printf("==========================\n"
         "  Daftar Kegiatan di UMN\n"
         "==========================\n");
  printf("1. Tampilkan Kegiatan\n"
         "2. Urutkan Kegiatan\n"
         "3. Cari Kegiatan\n"
         "4. Tambah Kegiatan\n"
         "0. Keluar\n");
  printf("Pilihan: ");
  return scanf("%d%*c", &menu) >= 0 ? menu : -1;
}

void swap(Kegiatan *b1, Kegiatan *b2) {
  Kegiatan temp = *b1;
  *b1 = *b2;
  *b2 = temp;
}

void bubbleSort(Kegiatan arr[], int size) {
  int i, j;
  for (i = 0; i < size - 1; i++)
    for (j = 0; j < size - i - 1; j++)
      if (strcmp(arr[j].nama, arr[j + 1].nama) > 0)
        swap(&arr[j], &arr[j + 1]);
}

void selectionSort(Kegiatan arr[], int size) {
  int i, j, min;
  for (i = 0; i < size - 1; i++) {
    min = i;
    for (j = i + 1; j < size; j++)
      if (strcmp(arr[j].nama, arr[min].nama) < 0)
        min = j;
    if (min != i)
      swap(&arr[min], &arr[i]);
  }
}

void urutKegiatan() {
  int menu;
  printf("==========================\n"
         "     Urutkan Kegiatan \n"
         "==========================\n");
  printf("1. Bubble Sort\n"
         "2. Selection Sort\n"
         "0. Keluar\n");
  printf("Pilihan: ");
  scanf("%d", &menu);

  switch (menu) {
  case 1:
    bubbleSort(DB, DB_SIZE);
    break;
  case 2:
    selectionSort(DB, DB_SIZE);
    break;
  case 0:
    return;
  default:
    printf("Menu tidak ditemukan!\n");
    break;
  }
}

void printElement(Kegiatan data) {
  printf("%-15s: %d\n", "ID", data.id);
  printf("%-15s: %s\n", "Nama Kegiatan", data.nama);
  printf("%-15s: %s\n", "Jenis", data.jenis);
  printf("%-15s: %s\n", "Bidang", data.bidang);
}

void seqSearch(Kegiatan arr[], int size, char val[]) {
  int i;
  for (i = 0; i < size; i++) {
    if (strcasecmp(arr[i].nama, val) == 0) {
      printf("\nData ditemukan!\n");
      printElement(arr[i]);
      printf("\n");
      return;
    }
  }
  printf("Data tidak ditemukan!\n");
}

void binSearch(Kegiatan arr[], int size, char val[]) {
  int low = 0, high = size, mid;
  while (low <= high) {
    mid = (high + low) / 2;
    if (strcasecmp(val, arr[mid].nama) == 0) {
      printf("\nData ditemukan!\n");
      printElement(arr[mid]);
      printf("\n");
      return;
    }
    if (strcasecmp(val, arr[mid].nama) < 0)
      high = mid - 1;
    else
      low = mid + 1;
  }
  printf("Data tidak ditemukan!\n");
}

void searchKegiatan() {
  int menu;
  char input[50];
  printf("==========================\n"
         "     Urutkan Kegiatan \n"
         "==========================\n");
  printf("1. Sequential Search\n"
         "2. Binary Search\n"
         "0. Keluar\n");
  printf("Pilihan: ");
  scanf("%d%*c", &menu);
  fflush(stdin);
  printf("Input nama yang ingin dicari: ");
  scanf("%[^\n]", input);
  switch (menu) {
  case 1:
    seqSearch(DB, DB_SIZE, input);
    break;
  case 2:
    binSearch(DB, DB_SIZE, input);
    break;
  case 0:
    return;
  default:
    printf("Menu tidak ditemukan!\n");
    break;
  }
}

void addData(Kegiatan arr[], int *size) {
  printf("=========================\n"
         "     Tambah Kegiatan\n"
         "=========================\n");
  printf("%-15s %-15s\n", "Jenis : ", "Bidang : ");
  printf("%-15s %-15s\n", "- UKM ", "- Olahraga");
  printf("%-15s %-15s\n", "- Komunitas", "- Sains & Sosial ");
  printf("%-15s %-15s\n", "- LSO", "- Seni & Budaya");
  printf("%-15s %-15s\n", "", "- Unspecified");

  Kegiatan input;

  printf("%-10s : ", "Nama Kegiatan");
  scanf("%[^\n]%*c", input.nama);

  while (1) {
    printf("%-10s : ", "Jenis");
    scanf("%[^\n]%*c", input.jenis);
    if (strcasecmp("UKM", input.jenis) == 0 ||
        strcasecmp("Komunitas", input.jenis) == 0 ||
        strcasecmp("LSO", input.jenis) == 0) {
      break;
    }
    printf("Input tidak valid!\n");
  };

  printf("%-10s : ", "Bidang");
  scanf("%[^\n]%*c", input.bidang);

  input.id = rand() % 100;
  printf("%-10s : %i\n", "ID", input.id);

  arr[*size] = input;
  *size += 1;
}

int main(void) {
  readFile(DB, &DB_SIZE);
  while (1) {
    switch (mainMenu()) {
    case 1:
      printList(DB, DB_SIZE);
      printf("\n");
      break;
    case 2:
      urutKegiatan();
      writeFile(DB, DB_SIZE);
      break;
    case 3:
      searchKegiatan();
      break;
    case 4:
      addData(DB, &DB_SIZE);
      writeFile(DB, DB_SIZE);
      break;
    case 0:
      return 0;
    default:
      printf("Menu tidak ditemukan!\n");
      break;
    }
  }
}
