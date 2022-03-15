#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
  // char data[10][50] = {"sapi",  "kambing", "guguk", "domba", "ayam",
  //                      "bebek", "burung",  "ikan",  "lebah", "kuda"};

  // Pertama kita perlu mengurutkan datanya dalam bentuk ascending atau
  // descending. (Saya mengurutkan secara manual)
  char data[10][50] = {"ayam", "bebek",   "burung", "domba", "guguk",
                       "ikan", "kambing", "kuda",   "lebah", "sapi"};

  bool check = false;

  // Variabel mid kita pindahkan dari dalam while loopnya keluar.
  // agar variabel ini bisa diakses diluar scope while loopnya.
  int mid, jumlahdata = 10, low = 0, high = jumlahdata - 1;

  char i[50];
  scanf("%s", i);

  while (low <= high) {

    // Kita assign value pada mid dengan menggunakan rumus berikut
    // untuk mencari nilai tengahnya
    mid = (low + high) / 2;

    // Yang kita bandingkan adalah value yang ingin dicari (variabel i)
    // dengan elemen data yang ada pada index mid.
    // Jika benar, maka langsung keluar dari loopnya.
    if (strcmp(i, data[mid]) == 0) {
      check = true;
      break;
    }

    // Lalu kita buat suatu kondisi jika ternyata elemen mid tidak sama dengan
    // value yang dicari.

    // Pertama jika value yang ingin dicari memiliki nilai yang lebih besar
    // dari titik tengahnya, maka kita cari titik tengahnya di kuadran sebelah
    // kanan

    if (strcmp(i, data[mid]) > 0) {
      low = mid + 1;

      // Jika ternyata nilai yang dicari lebih kecil dari titik tengah,
      // maka kita cari titik tengahnya di kuadran sebelah kiri
    } else {
      high = mid - 1;
    }

    // Lalu kita ulangi lagi proses loop ini.
  }

  if (check == true) {
    printf("Data Found\n");
    // Yang diprint adalah elemen data yang ada dalam index mid,
    // bukan elemen pada variabel i.
    printf("%s", data[mid]);
  } else {
    printf("Data not found!\n");
  }

  return 0;
}
