#include <stdio.h>
#include <stdlib.h>

void swap(int *bil1, int *bil2) {
  int temp;

  temp = *bil1;
  *bil1 = *bil2;
  *bil2 = temp;
}

void heapify(int *bil, int n, int i) {
  int maks = i;
  int l = 2 * i + 1;
  int r = 2 * i + 2;

  if (l < n && bil[l] < bil[maks]) {
    maks = l;
  }

  if (r < n && bil[r] < bil[maks]) {
    maks = r;
  }

  if (maks != i) {
    swap(&bil[i], &bil[maks]);

    heapify(bil, n, maks);
  }
}

void heapSort(int *bil, int n) {
  int i;

  for (i = n / 2 - 1; i >= 0; i--) {
    heapify(bil, n, i);
  }

  for (i = n - 1; i >= 0; i--) {
    swap(&bil[0], &bil[i]);

    heapify(bil, i, 0);
  }
}

int main(int argc, char const *argv[]) {
  int *bil, n, i;

  printf("Jumlah bilangan: ");
  scanf("%d", &n);

  bil = (int *)malloc(sizeof(int) * n);

  for (i = 0; i < n; i++)
    scanf("%d", &bil[i]);

  heapSort(bil, n);

  printf("Hasil pengurutan: ");
  for (i = 0; i < n; i++)
    printf("%d ", bil[i]);

  printf("\n");

  return 0;
}
