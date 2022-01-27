#include <stdio.h>

int main() {
  int randomNumber[] = {10, 24, 234, 345, 234};

  printf("randomNumber = %p\n", randomNumber);
  printf("&randomNumber = %p\n", &randomNumber);
  printf("&randomNumber[0] = %p\n\n", &randomNumber[0]);

  // Pointer dalam array menunjuk ke array ke 0
  printf("randomNumber = %d\n", randomNumber[0]);
  printf("*randomNumber = %d\n\n", *randomNumber);

  // Pointer menunjuk ke dalam array index ke 2
  // dengan menjumlahkan sesuai index
  printf("randomNumber[2] = %d\n", randomNumber[2]);
  printf("*(randomNumber+2) = %d\n\n", *(randomNumber + 2));

  // Bagaimana dengan alamat array index ke 2?
  printf("&randomNumber[2] = %p\n", &randomNumber[2]);
  // Apa yang berbeda dengan &randomNumber?

  return 0;
}
