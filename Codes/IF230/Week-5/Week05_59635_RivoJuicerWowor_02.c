#include <malloc.h>
#include <stdio.h>

void swap(int *bil1, int *bil2) {
  int temp;

  temp = *bil1;
  *bil1 = *bil2;
  *bil2 = temp;
}

void selectionSort(int *bil, int n) {
  int i, j, temp;
  for (i = 0; i < n; i++) {
    printf("iteration i = %d\n", i);
    temp = i;
    for (j = i + 1; j < n; j++) {
      printf("iteration j = %d\n", j);

      // Kita hanya perlu menukar simbol perbandingan
      // di dalam if statementnya untuk mengubah order
      // dari ascending ke descending
      if (bil[j] > bil[temp])
        temp = j;
    }
    if (temp != i)
      swap(&bil[temp], &bil[i]);
  }
  printf("total iteration = %d\n", i + j);
}

int main(int argc, char const *argv[]) {
  int i, n, *bil;

  printf("Banyak bilangan: ");
  scanf("%d", &n);

  bil = (int *)malloc(sizeof(int) * n);
  for (i = 0; i < n; i++) {
    printf("Input bilangan ke-%d: ", i + 1);
    scanf("%d", &bil[i]);
  }
  printf("\n");

  selectionSort(bil, n);

  printf("Hasil sort: ");
  for (i = 0; i < n; i++) {
    printf("%d ", bil[i]);
  }
  printf("\n");

  free(bil);

  return 0;
}
