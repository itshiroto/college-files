#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>

int *sel_sort(int *arr, int start, int end) {
  for (int i = start; i < end; i++) {
    for (int j = start + i; j < end; j++) {
      if (arr[i] > arr[j]) {
        int temp = arr[j];
        arr[j] = arr[i];
        arr[i] = temp;
      }
    }
  }
  return arr;
}

int main(void) {
  int *arr;
  arr = (int *)malloc(sizeof(int) * 5);
  for (int i = 0; i < 5; i += 1) {
    arr[i] = 500 + rand() % 1000;
  }
  arr = sel_sort(arr, 0, 5);
  for (int i = 0; i < 5; i += 1) {
    printf("%d ", arr[i]);
  }
  free(arr);
  return 0;
}
