#include <malloc.h>
#include <stdio.h>

void swap(int *bil1, int *bil2) {
  int temp = *bil1;
  *bil1 = *bil2;
  *bil2 = temp;
}

void customBubbleSort(int *bil, int start, int end) {
  int i, j;
  for (i = start + 1; i <= end; i++) {
    for (j = end; j >= i; j--) {
      if (bil[j] > bil[j - 1]) {
        swap(&bil[j], &bil[j + 1]);
      }
    }
  }
  printf("Hasil sort dalam function: ");
  for (int i = 0; i < 11; i++) {
    printf("%d ", bil[i]);
  }
  printf("\n");
}

int main(void) {
  int *bil;
  bil = (int *)malloc(sizeof(int) * 11);
  for (int i = 0; i < 11; i++) {
    printf("Input bilangan ke-%d: ", i + 1);
    scanf("%d", &bil[i]);
  }
  // int bil[] = {100, 99, 88, 77, 66, 55, 44, 33, 22, 11, 0};
  customBubbleSort(bil, 2, 8);

  printf("Hasil sort: ");
  for (int i = 0; i < 11; i++) {
    printf("%d ", bil[i]);
  }
  printf("\n");
  // free(bil);

  return 0;
}
