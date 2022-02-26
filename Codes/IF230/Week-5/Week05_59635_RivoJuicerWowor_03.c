#include <malloc.h>
#include <stdio.h>

void insertionSort(int *bil, int n) {
  int i, j, temp;

  for (i = 1; i < n; i++) {
    temp = bil[i];
    for (j = i - 1; j >= 0 && bil[j] > temp; j--) {
      bil[j + 1] = bil[j];
    }

    bil[j + 1] = temp;
  }
}

int main(int argc, char const *argv[]) {
  int i, j, temp;
  int n;
  int *bil;
  scanf("%d", &n);

  bil = (int *)malloc(sizeof(int) * n);

  for (i = 0; i < n; i++) {
    printf("Input bilangan ke-%d: ", i + 1);
    scanf("%d", &bil[i]);
  }
  printf("\n");

  insertionSort(bil, n);

  printf("Hasil sort: ");
  for (i = 0; i < n; i++) {
    printf("%d ", bil[i]);
  }
  printf("\n");

  free(bil);

  return 0;
}
