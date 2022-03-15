#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(int *xp, int *yp) {
  int temp = *xp;
  *xp = *yp;
  *yp = temp;
}

void bubbleSort(int arr[], int n) {
  int i, j;
  for (i = 0; i < n - 1; i++)
    for (j = 0; j < n - i - 1; j++)
      if (arr[j] > arr[j + 1])
        swap(&arr[j], &arr[j + 1]);
}

int SearchInterpolation(int data[], int n, int searchKey) {
  int position, low, high;
  low = 0;
  high = n - 1;

  do {
    printf("=================\n");
    printf("Low: %d, High: %d\n", low, high);
    printf("Position: (%d - %d) * (%d - %d) / (%d - %d) + %d\n", searchKey,
           data[low], high, low, data[high], data[low], low);

    position =
        (searchKey - data[low]) * (high - low) / (data[high] - data[low]) + low;
    printf("Position: %d\n", position);
    printf("=================\n");
    if (data[position] == searchKey)
      return position;
    if (data[position] > searchKey)
      high = position - 1;
    else
      low = position + 1;
    printf("\n");
  } while (searchKey >= data[low] && searchKey <= data[high]);

  return -1;
}

void printArr(int arr[], int n) {
  printf("\n");
  for (int i = 0; i < n - 1; i++)
    printf("idx [%d]: %d\n", i, arr[i]);
}

int main() {
  int data[] = {13728, 13613, 16358, 13610, 14026, 14261, 14152, 13411, 17942};
  int size = sizeof(data) / sizeof(data[0]);

  printf("Data before sorted: ");
  printArr(data, size);
  printf("\n");

  bubbleSort(data, size);

  printf("Data after sorted: ");
  printArr(data, size);
  printf("\n");

  int x = 14261;
  int idx = SearchInterpolation(data, size - 1, x);
  printf("\n");
  if (idx != 1) {
    printf("Data found in index %d!\n", idx);
    printf("Data: %d\n", data[idx]);
  } else {
    printf("Data not found!\n");
  }

  return 0;
}
