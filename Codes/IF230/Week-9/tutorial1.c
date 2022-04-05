#include <stdbool.h>
#include <stdio.h>

int main() {
  int hashT[10] = {1, 3, 2, 2, 4, 5, 7, 8, 9, 2};
  int inputKey;
  scanf("%d", &inputKey);

  int hash;
  bool check = false;

  hash = inputKey % 10;
  int temp = hash;
  while (1) {
    if (hashT[temp] == 0) {
      hashT[temp] = inputKey;
      break;
    }
    temp++;
    if (hash == temp) {
      printf("Hash Table penuh");
      break;
    }
    if (temp > 9) {
      temp = 0;
    }
  }

  int i;
  for (i = 0; i < 10; i++) {
    printf("[%d]", hashT[i]);
  }
  return 0;
}
