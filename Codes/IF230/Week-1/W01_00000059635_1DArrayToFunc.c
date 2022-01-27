#include <stdio.h>

int sum(int receivedArr[]) {
  int i, result = 0;
  for (i = 0; i < 5; i++) {
    result += receivedArr[i];
  }
  return result;
}

int main() {
  int randomNumber[5] = {10, 24, 234, 345, 234};
  int i;

  // Jika hasil penjumlahan mau disimpan ke dalam
  // variabel

  int total;
  total = sum(randomNumber);
  printf("Hasil penjumlahan = %d\n", total);

  // Jika hasil penjumlahan hanya akan ditampilkan
  printf("Hasil penjumlahan = %d\n", sum(randomNumber));

  return 0;
}
