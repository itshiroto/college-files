#include <stdbool.h>
#include <stdio.h>

bool int_search(int *data, int query, int n) {
  int low = 0;
  int high = n;
  int mid = low + (((double)(high - low) / (data[high] - data[low])) *
                   (query - data[low]));
  while (low <= high && query >= data[low] && query <= data[high]) {
    if (query < data[mid]) {
      high = mid - 1;
    } else if (query > data[mid]) {
      low = mid + 1;
    } else {
      return true;
    }
    mid = low + (((double)(high - low) / (data[high] - data[low])) *
                 (query - data[low]));
  }
  return false;
}

int main(void) {
  int arr[] = {9, 1, 2, 10, 100, 15, 20, 18, 17};
  int que[] = {5, 2, 10, 15, 200, 1};
  int arr_size = sizeof(arr) / sizeof(arr[0]);
  int que_size = sizeof(que) / sizeof(que[0]);
  int i = 0;
  for (i = 0; i < que_size; i++) {
    i
  }
}
