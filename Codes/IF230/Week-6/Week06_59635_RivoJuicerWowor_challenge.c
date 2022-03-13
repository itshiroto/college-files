#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// #define DEBUG 1

typedef struct Mahasiswa {
  char nama[30];
  int nilaiTugas[15];
  int nilaiAkhir;

  struct Mahasiswa *next, *prev;
} Mahasiswa;

// FUNCTION FOR LINKED LIST INPUT (MENU 1)
// =======================================

int calcAvg(int *nilaiTugas) {
  int sum = 0;
  for (int i = 0; i < 15; i++) {
    sum += nilaiTugas[i];
  }
  return sum / 15;
}

void inputData(char nama[30], int *nilaiTugas, int *nilaiAkhir) {
  printf("%-6s : ", "Nama");
  scanf("%[^\n]%*c", nama);
  for (int i = 0; i < 15; i++) {
    printf("%s%-4i : ", "Nilai Tugas ", i + 1);
    scanf("%i", &nilaiTugas[i]);
  }
  *nilaiAkhir = calcAvg(nilaiTugas);
}

void addNode(Mahasiswa **head, Mahasiswa **tail) {
  Mahasiswa *node = (Mahasiswa *)malloc(sizeof(Mahasiswa));
  // if (DEBUG == 1) {
  //   strcpy(node->nama, "Rivo");
  //   int nilaiTugas[] = {80, 90, 80, 70, 75, 78, 98, 75,
  //                       85, 98, 71, 74, 86, 79, 89};
  //   for (int i = 0; i < 15; i++)
  //     node->nilaiTugas[i] = nilaiTugas[i];
  //   node->nilaiAkhir = calcAvg(node->nilaiTugas);
  // } else
  inputData(node->nama, node->nilaiTugas, &node->nilaiAkhir);

  if (*head == NULL && *tail == NULL) {
    *head = *tail = node;
    (*head)->next = (*tail)->next = NULL;
    (*head)->prev = (*tail)->prev = NULL;
  } else {
    node->prev = *tail;
    (*tail)->next = node;
    *tail = node;
  }
}

void printNode(Mahasiswa **head, Mahasiswa **tail) {
  if (*head == NULL) {
    printf("Data masih kosong!\n");
    return;
  }
  Mahasiswa *temp = *head;
  while (temp != NULL) {
    printf("==========\n");
    printf("Nama: %s\n", temp->nama);
    printf("Nilai Tugas: ");
    for (int i = 0; i < 15; i++) {
      printf("%i ", temp->nilaiTugas[i]);
    }
    printf("\n");
    printf("Nilai Akhir: %i\n", temp->nilaiAkhir);
    temp = temp->next;
  }
}

int printMainMenu() {
  int choice;
  printf("==========\n");
  printf("1) Input data\n"
         "2) Sort nilai\n"
         "3) Exit\n");
  printf("Pilihan: ");
  scanf("%i%*c", &choice);
  return choice;
}

// FUNCTION FOR SORTING ALGORITHM (MENU 2)
// =======================================
void swap(int *bil1, int *bil2) {
  int temp;
  temp = *bil1;
  *bil1 = *bil2;
  *bil2 = temp;
}

// Quick Sort

int partition(int *bil, int l, int r, char dir) {
  int pivot = bil[r];
  int i = l - 1;
  for (int j = l; j <= r - 1; j++) {
    if ((bil[j] >= pivot && dir == 'd') || (bil[j] <= pivot && dir == 'a')) {
      i++;
      swap(&bil[i], &bil[j]);
    }
  }
  swap(&bil[i + 1], &bil[r]);
  return (i + 1);
}

void quickSort(int *bil, int l, int r, char dir) {
  if (l < r) {
    int pi = partition(bil, l, r, dir);
    quickSort(bil, l, pi - 1, dir);
    quickSort(bil, pi + 1, r, dir);
  }
}

// Merge Sort
void merge(int *bil, int l, int m, int r, char choice) {
  int n1 = m - l + 1, n2 = r - m;
  int i, j, k, L[n1], R[n2];

  for (i = 0; i < n1; i++) {
    L[i] = bil[l + i];
  }
  for (j = 0; j < n2; j++) {
    R[j] = bil[m + 1 + j];
  }
  i = j = 0;
  k = l;

  while (i < n1 && j < n2) {
    if ((L[i] <= R[j] && choice == 'a') || (L[i] >= R[j] && choice == 'd')) {
      bil[k] = L[i];
      i++;
    } else {
      bil[k] = R[j];
      j++;
    }
    k++;
  }
  while (i < n1) {
    bil[k] = L[i];
    i++;
    k++;
  }
  while (j < n2) {
    bil[k] = R[j];
    j++;
    k++;
  }
}

void mergeSort(int *bil, int l, int r, char choice) {
  if (l < r) {
    int m = (l + r) / 2;

    mergeSort(bil, l, m, choice);
    mergeSort(bil, m + 1, r, choice);

    merge(bil, l, m, r, choice);
  }
}

// Shell Sort
void shellSort(int *arr, int n, char choice) {
  int i, j, gap;

  for (gap = n / 2; gap > 0; gap /= 2) {
    for (i = gap; i < n; i++) {
      int temp = arr[i];
      for (j = i; j >= gap; j -= gap) {
        if ((arr[j - gap] > temp && choice == 'a') ||
            (arr[j - gap] < temp && choice == 'd')) {
          arr[j] = arr[j - gap];
          continue;
        }
        break;
      }
      arr[j] = temp;
    }
  }
}

// Heap Sort
void heapify(int *bil, int n, int i, char choice) {
  int maks = i;
  int l = 2 * i + 1;
  int r = 2 * i + 2;

  if (l < n)
    if ((bil[l] > bil[maks] && choice == 'a') ||
        (bil[l] < bil[maks] && choice == 'd'))
      maks = l;

  if (r < n && bil[r] < bil[maks])
    if ((bil[r] > bil[maks] && choice == 'a') ||
        (bil[r] < bil[maks] && choice == 'd'))
      maks = r;

  if (maks != i) {
    swap(&bil[i], &bil[maks]);
    heapify(bil, n, maks, choice);
  }
}

void heapSort(int *bil, int n, char choice) {
  int i;

  for (i = n / 2 - 1; i >= 0; i--) {
    heapify(bil, n, i, choice);
  }

  for (i = n - 1; i >= 0; i--) {
    swap(&bil[0], &bil[i]);

    heapify(bil, i, 0, choice);
  }
}

void sortMenu(Mahasiswa **head, Mahasiswa **tail) {
  if (*head == NULL && *tail == NULL) {
    printf("\nData masih kosong!\n");
    return;
  }
  int sortMenu;
  char directionMenu;
  bool keepGoing = true;
  Mahasiswa *temp = *head;
  printf("\n"
         "1) Quick Sort\n"
         "2) Merge Sort\n"
         "3) Shell Sort\n"
         "4) Heap Sort\n"
         "5) Kembali ke menu utama\n");
  printf("Pilihan: ");
  scanf("%d%*c", &sortMenu);

  printf("Ascending (a) or Descending (d): ");
  scanf("%c%*c", &directionMenu);
  directionMenu = tolower(directionMenu);
  if (directionMenu != 'a' && directionMenu != 'd') {
    printf("\nMenu sort tidak ditemukan!\n");
    return;
  }

  while (temp != NULL && keepGoing) {
    switch (sortMenu) {
    case 1:
      quickSort(temp->nilaiTugas, 0, 14, directionMenu);
      temp->nilaiAkhir = calcAvg(temp->nilaiTugas);
      break;
    case 2:
      mergeSort(temp->nilaiTugas, 0, 14, directionMenu);
      temp->nilaiAkhir = calcAvg(temp->nilaiTugas);
      break;
    case 3:
      shellSort(temp->nilaiTugas, 15, directionMenu);
      temp->nilaiAkhir = calcAvg(temp->nilaiTugas);
      break;
    case 4:
      heapSort(temp->nilaiTugas, 15, directionMenu);
      temp->nilaiAkhir = calcAvg(temp->nilaiTugas);
      break;
    case 5:
      keepGoing = 0;
    default:
      printf("\nMenu tidak ditemukan!\n");
      return;
    }
    temp = temp->next;
  }
  printf("\n Data berhasil di sort!\n");
}

// MAIN FUNCTION
// =======================================
int main() {
  Mahasiswa *head, *tail;
  head = tail = NULL;
  while (1) {
    printf("\n");
    printNode(&head, &tail);
    switch (printMainMenu()) {
    case 1:
      addNode(&head, &tail);
      break;
    case 2:
      sortMenu(&head, &tail);
      break;
    case 3:
      return 0;
    default:
      printf("\nMenu tidak ditemukan!\n");
      break;
    }
  }
}
