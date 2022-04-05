#include <stdio.h>
#include <string.h>

struct Mahasiswa {
  char nama[50];
  int nilaiAkhir;
};

int main() {
  struct Mahasiswa data;
  strcpy(data.nama, "Rivo");
  data.nilaiAkhir = 90;
  printf("%s\n", data.nama);
  printf("%d\n", data.nilaiAkhir);
}
