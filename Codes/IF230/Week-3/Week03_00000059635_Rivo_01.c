#include <malloc.h>
#include <stdio.h>

int main() {
  int ***arr = (int ***)malloc(sizeof(int **) * 10);
  for (int i = 0; i < 10; i++) {
    arr[i] = (int **)malloc(sizeof(int *) * 10);
    for (int j = 0; j < 10; j++) {
      arr[i][j] = (int *)malloc(sizeof(int) * 10);
    }
  }

  int count = 0;

  for (int i = 0; i < 10; i++)
    for (int j = 0; j < 10; j++)
      for (int k = 0; k < 10; k++)
        arr[i][j][k] = ++count;

  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      for (int k = 0; k < 10; k++) {
        printf("%d ", arr[i][j][k]);
      }
      free(arr[i][j]);
    }
    free(arr[i]);
  }
  free(arr);
}
