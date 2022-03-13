#include <stdio.h>
#include <stdlib.h>

void shellSort(int *arr, int n) {
  int i, j, gap;

  for (gap = n / 2; gap > 0; gap /= 2) {
    for (i = gap; i < n; i++) {
      int temp = arr[i];
      for (j = i; j >= gap; j -= gap) {
        if (arr[j - gap] < temp) {
          arr[j] = arr[j - gap];
          continue;
        }
        break;
      }
      arr[j] = temp;
    }
  }
}

int main(int argc, char const *argv[]) {
  int i, n, *arr;
  printf("Input N = ");
  scanf("%d", &n);
  arr = (int *)malloc(sizeof(int) * n);
  for (i = 0; i < n; i++) {
    printf("Masukkan bilangan : ");
    scanf("%d", &arr[i]);
  }
  shellSort(arr, n);
  printf("Hasil Sort : ");
  for (i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  return 0;
}
