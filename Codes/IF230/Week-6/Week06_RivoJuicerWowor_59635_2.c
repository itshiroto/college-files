#include <stdio.h>
#include <stdlib.h>

void merge(int *bil, int l, int m, int r) {
  int i, j, k;
  int n1 = m - l + 1;
  int n2 = r - m;
  int L[n1], R[n2];

  for (i = 0; i < n1; i++) {
    L[i] = bil[l + i];
  }
  for (j = 0; j < n2; j++) {
    R[j] = bil[m + 1 + j];
  }
  i = j = 0;
  k = l;

  while (i < n1 && j < n2) {
    if (L[i] >= R[j]) {
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

void mergeSort(int *bil, int l, int r) {
  if (l < r) {
    int m = (l + r) / 2;

    mergeSort(bil, l, m);
    mergeSort(bil, m + 1, r);

    merge(bil, l, m, r);
  }
}

int main(void) {
  int *bil, n, i;

  printf("Jumlah bilangan: ");
  scanf("%d", &n);

  bil = (int *)malloc(sizeof(int) * n);

  for (i = 0; i < n; i++) {
    scanf("%d", &bil[i]);
  }

  mergeSort(bil, 0, n - 1);

  printf("Hasil Pengurutan: ");
  for (i = 0; i < n; i++) {
    printf("%d ", bil[i]);
  }

  return 0;
}
