#include <stdio.h>

void inputMatrix(int matrix[3][3]) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      scanf("%d", &matrix[i][j]);
    }
  }
  printf("\n");
}

void printMatrix(int matrix[3][3]) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

void kaliMatrix(int m1[3][3], int m2[3][3]) {
  int res[3][3] = {0};
  int row, col, i;
  for (row = 0; row < 3; row++) {
    for (col = 0; col < 3; col++) {
      for (i = 0; i < 3; i++) {
        res[row][col] += m1[row][i] * m2[i][col];
      }
    }
  }
  printMatrix(res);
}

void tambahMatrix(int m1[3][3], int m2[3][3]) {
  int res[3][3];
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      res[i][j] = m1[i][j] + m2[i][j];
    }
  }
  printMatrix(res);
}

void transposeMatrix(int matrix[3][3]) {
  int transposed[3][3];
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      transposed[i][j] = matrix[j][i];
    }
  }
  printMatrix(transposed);
}

int menuChoice() {
  int menu;
  printf("1. Perkalian Dua Buah Matrix\n");
  printf("2. Penjumlahan Dua Buah Matrix\n");
  printf("3. Transpose Dua Buah Matrix\n");
  printf("4. Keluar\n");
  printf("Pilihan: ");
  scanf("%d", &menu);
  return menu;
}

int main() {
  int matrix1[3][3];
  int matrix2[3][3];

  printf("Masukkan Matrix Pertama (3 x 3): \n");
  inputMatrix(matrix1);

  printf("Masukkan Matrix Kedua (3 x 3): \n");
  inputMatrix(matrix2);

  while (1) {
    int menu = menuChoice();
    switch (menu) {
    case 1:
      kaliMatrix(matrix1, matrix2);
      break;
    case 2:
      tambahMatrix(matrix1, matrix2);
      break;
    case 3:
      printf("Transpose Matrix Pertama\n");
      transposeMatrix(matrix1);

      printf("Transpose Matrix Kedua\n");
      transposeMatrix(matrix2);
      break;
    case 4:
      return 0;
    default:
      printf("Menu tidak ditemukan\n");
      break;
    }
  }
}
