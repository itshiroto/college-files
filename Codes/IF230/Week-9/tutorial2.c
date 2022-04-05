#include <stdio.h>
#include <stdlib.h>

void sieve(int prime[], int n, int *x) {
  int i, j, p;
  int temp[n * 2];

  for (i = 0; i < n * 2; i++) {
    temp[i] = 1;
  }

  for (p = 2; p * p <= n * 2; p++) {
    if (temp[p] == 1) {
      for (i = p * 2; i <= n * 2; i += p) {
        temp[i] = 0;
      }
    }
  }

  j = 0;

  for (i = 2; i < n; i++) {
    if (temp[i] == 1) {
      prime[j] = i;
      j++;
    }
  }
  *x = j;
}

int hashFunction(int number, int size) { return number % size; }

int main(int argc, char const *argv[]) {
  int *hashTable, *primeTable;
  int i, j, choose, index;
  int primeCount = 0;
  int capacity = 0, percentage = 0;
  int initSize = 10;
  int size = initSize;

  hashTable = (int *)malloc(sizeof(int) * initSize);
  primeTable = (int *)malloc(sizeof(int) * 10000);

  for (i = 0; i < initSize; i++)
    hashTable[i] = -1;

  for (i = 0; i < 10000; i++)
    primeTable[i] = 0;

  sieve(primeTable, 10000, &primeCount);

  index = 0;

  do {
    printf("1. Input number\n"
           "2. Show Hash Table\n"
           "0. Exit\n"
           "Choose: ");
    scanf("%d", &choose);
    if (choose == 1) {
      int number, hash;
      int done = 0;
      printf("Input one random number: ");
      scanf("%d", &number);
      capacity++;
      hash = hashFunction(number, size);
      while (!done) {
        if (hashTable[hash] == -1) {
          hashTable[hash] = number;
          done = 1;
        } else
          hash++;

        if (hash == size)
          hash = 0;
      }

      percentage = (capacity * 100) / size;
      printf("Capacity of hash table = %d%%\n", percentage);

      if (percentage >= 70) {
        printf("Hash Table almost full. Making new hash table!\n");

        int *arrTemp;
        arrTemp = (int *)malloc(sizeof(int) * capacity);
        j = 0;
        for (i = 0; i < size; i++) {
          if (hashTable[i] != -1) {
            arrTemp[j] = hashTable[i];
            j++;
          }
        }
        free(hashTable);

        size *= 2;

        for (i = 0; i < primeCount; i++) {
          if (primeTable[i] > size) {
            size = primeTable[i];
            break;
          }
        }

        hashTable = (int *)malloc(sizeof(int) * size);
        for (i = 0; i < size; i++) {
          hashTable[i] = -1;
        }

        for (i = 0; i < capacity; i++) {
          hash = hashFunction(arrTemp[i], size);
          done = 0;
          while (!done) {
            if (hashTable[hash] == -1) {
              hashTable[hash] = arrTemp[i];
              done = 1;
            } else
              hash++;

            if (hash == size)
              hash = 0;
          }
        }

        free(arrTemp);
      } else {
        printf("Hash Table still can be used\n");
      }
      getchar();
    } else if (choose == 2) {
      printf("Content of hash table:\n");
      for (i = 0; i < size; i++) {
        printf("Hash Table[%d] = %d\n", i, hashTable[i]);
      }
      getchar();
    } else if (choose == 0) {
      free(hashTable);
      break;
    } else
      continue;
  } while (1);

  return 0;
}
