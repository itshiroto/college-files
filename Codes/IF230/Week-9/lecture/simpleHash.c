#include <stdio.h>
#include <string.h>

#define BUCKET_NUM 5;

int simple_hash(char *arr) {
  int i, sum = 0;
  for (i = 0; i < strlen(arr); i++) {
    sum += (arr[i] - 'a') * i;
  }
  return sum % BUCKET_NUM;
}

int main() {
  char arr[100];
  printf("Number of bucket: %i\n", BUCKET_NUM);
  strcpy(arr, "Lorentzo");
}
