#include <stdio.h>

int main(void) {
  // Menentukan nilai pada array saat pembuatan
  int randomNumber[5] = {10, 24, 234, 345, 234};
  int i; // Variabel untuk melakukan iterasi

  printf("Isi awal array\n");
  for (i = 0; i < 5; i++) {
    printf("randomNumber[%d] = %d\n", i, randomNumber[i]);
  }

  printf("\n");
  randomNumber[3] = 10000;

  printf("Isi array setelah berubah\n");
  for (i = 0; i < 5; i++) {
    printf("randomNumber[%d] = %d\n", i, randomNumber[i]);
  }
  return 0;
}
