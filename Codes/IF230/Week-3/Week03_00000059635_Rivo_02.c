#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct orang {
  char nama[30];
  int usia;

  struct orang *next;
} orang;

int main(int argc, char const *argv[]) {
  orang *head, *curr, *node;
  // <a> Jelaskan kegunaan 3 variabel dalam potongan kode ini
  /*  JAWAB
      Ketiga variabel pointer ini (`head`, `curr`, dan `node`) akan menjadi
      variabel penunjuk yang penting bagi struktur data linked list kita
      nantinya.

      `head` akan menjadi titik start kita dalam menelusuri linked list yang
      akan kita buat.

      `curr` akan menjadi titik lokasi kita sekarang dalam linked list ketika
      kita menelusuri linked listnya.

      Dan `node` akan menjadi *template* atau struktur basis member/node dalam
      linked list ketika kita ingin menambahkan node dalam list tersebut.
  */

  char nama[30];
  int usia, exit = 1;
  char lanjut;

  head = curr = NULL;

  while (exit == 1) {
    system("clear"); // saya pakai linux kak
    printf("Data diri yagn akan dimasukkan dalam linked list\n");
    printf("------------------------------------------------\n\n");
    printf("Masukkan nama: ");
    scanf("%[^\n]", nama);
    printf("Masukkan usia: ");
    scanf("%i", &usia);
    getchar();

    node = (struct orang *)malloc(sizeof(struct orang));
    // <b> Apa kegunaan baris kode diatas?
    /*JAWAB
      Baris diatas bisa diterjemahkan sebagai berikut:
      Alokasikanlah ruang pada memori sebesar ukuran dari tipe data `struct
      orang` dan jadikan ruang memori tersebut sebagai pointer untuk `struct
      orang` tersebut
    */

    node->next = NULL;

    strcpy(node->nama, nama);
    node->usia = usia;

    //<c> Apa kegunaan baris kode berikut?
    /*JAWAB
      Jika node `head` masih kosong (tidak ada data),
      maka node `node` yang akan mengisi posisi `head` tersebut
      sebagai kepala dari linked listnya.
    */

    if (head == NULL)
      head = node;

    //<c> Apa kegunaan baris kode berikut? Apa yang membedakannya dengan <c>?
    /*JAWAB
      Jika head memiliki data didalamnya, maka node `curr` akan diisi oleh data
      yang ada didalam node `head`, anggap saja seperti kita memulai lokasi kita
      (`curr`) pada titik start di list kita (`head`);

      Setelah itu akan dilakukan looping untuk mencari node yang tidak memiliki
      data dalam pointer nextnya, atau bisa saja dibilang mencari node yang
      tidak memiliki tetangga. Dan setelah ditemukan node tersebut, kita isi
      pointer next pada node `curr` dengan data `node`.
    */

    else {
      curr = head;
      while (curr->next != NULL) {
        curr = curr->next;
      }
      curr->next = node;
    }

    //<e> Apa tujuan dari looping ini (pilih)?
    // B. Error handling sederhana

    do {
      printf("Lanjut (y/n)?: ");
      scanf("%c", &lanjut);
      getchar();
      if (lanjut == 'y' || lanjut == 'Y') {
        exit = 1;
        break;
      } else if (lanjut == 'n' || lanjut == 'N') {
        exit = 0;
        break;
      } else {
        printf("Masukkan input yang benar !\n");
        printf("Tekan tombol apapun untuk melanjutkan. . .\n");
      }
    } while (1);
  }

  system("clear");
  printf("Daftar nama yang terdapat dalam linked list\n");
  printf("-------------------------------------------\n\n");

  curr = head;

  // <f> Apa yang dilakukan dalam pengulangan berikut?
  /*JAWAB
    `while` loop dibawah akan mengoutput nama dan usia yang ada
    di dalam node `curr`, dan setelah itu dia akan pergi ke node tetangganya
    yang ada di next pada `curr` tersebut.
  */
  while (curr != NULL) {
    printf("Nama: %s\nUsia: %d\n", curr->nama, curr->usia);
    printf("-------------------------\n");
    curr = curr->next;
  }
  while (head != NULL) {
    /* <g> Tuliskan perintah untuk melakukan free memory dari head.
       Gunakan contoh potongan kode pada free sebagai petunjuk
    */
    orang *temp = head;
    head = temp->next;
    temp->next = NULL;
    free(temp);
  }
}
