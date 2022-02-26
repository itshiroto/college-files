#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>

struct linkedList {
  int value;
  struct linkedList *next;
};

void insertNode(int val, struct linkedList **head) {
  struct linkedList *temp =
      (struct linkedList *)malloc(sizeof(struct linkedList));
  temp->value = val;
  temp->next = NULL;

  if (*head == NULL) {
    *head = temp;
  } else {
    struct linkedList *ptr = *head;
    while (ptr->next != NULL) {
      ptr = ptr->next;
    }
    ptr->next = temp;
  }
}

int main(int argc, char const *argv[]) {
  int i, j, n, data[100], maks;

  struct linkedList *bucket[10];
  for (i = 0; i < 10; i++) {
    bucket[i] = NULL;
  }

  printf("Masukkan jumlah data yang akan di sort: ");
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    printf("Masukkan data ke-%d: ", i + 1);
    scanf("%d", &data[i]);
    if (i == 0 || maks < data[i]) {
      maks = data[i];
    }
  }

  int totalIterasi = 0;
  while (maks > 0) {
    maks /= 10;
    totalIterasi++;
  }
  printf("\nTotal iterasi yang akan dilakukan: %d\n", totalIterasi);

  int pembagi = 1;
  for (i = 0; i < totalIterasi; i++) {
    for (j = 0; j < n; j++) {
      int digit = (data[j] / pembagi) % 10;
      insertNode(data[j], &bucket[digit]);
    }
    pembagi *= 10;

    printf("\n====\nIterasi %d\n", i + 1);
    for (j = 0; j < 10; j++) {
      printf("Bucket[%d] : ", j);
      struct linkedList *ptr = bucket[j];
      while (ptr != NULL) {
        printf("%d, ", ptr->value);
        ptr = ptr->next;
      }
      printf("\n");
    }

    int idx = 0;
    for (j = 0; j < 10; j++) {
      struct linkedList *ptr = bucket[j];
      while (ptr != NULL) {
        data[idx] = ptr->value;
        idx++;
        ptr = ptr->next;
      }
    }

    printf("Hasil array sementara: ");
    for (j = 0; j < n; j++) {
      printf("%d ", data[j]);
    }
    printf("\n====\n\n");

    for (j = 0; j < 10; j++) {
      struct linkedList *temp, *ptr = bucket[j];
      while (ptr != NULL) {
        temp = ptr;
        ptr = ptr->next;
        free(temp);
      }
      bucket[j] = NULL;
    }
  }

  printf("Hasil setelah di sort: ");
  for (i = 0; i < n; i++) {
    printf("%d, ", data[i]);
  }
  printf("\n");

  return 0;
}
