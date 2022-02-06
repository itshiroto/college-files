#include <stdio.h>

struct Mahasiswa {
  char nama[100];
  char nim[20];
  char prodi[100];
};

int main() {
  char keepGoing = 'a';
  FILE *outputFile;
  struct Mahasiswa MAHASISWADB;

  outputFile = fopen("mahasiswa_db.txt", "w");

  while (1) {
    printf("Nama: ");
    scanf("%[^\n]%*c", MAHASISWADB.nama);

    printf("NIM: ");
    scanf("%[^\n]%*c", MAHASISWADB.nim);

    printf("Prodi: ");
    scanf("%[^\n]%*c", MAHASISWADB.prodi);

    fprintf(outputFile, "%s, %s, %s\n", MAHASISWADB.nama, MAHASISWADB.nim,
            MAHASISWADB.prodi);

    printf("Keep going? (y/N): ");
    scanf("%c%*c", &keepGoing);
    if (!(keepGoing == 'Y' || keepGoing == 'y')) {
      break;
    }
  }

  fclose(outputFile);
}
