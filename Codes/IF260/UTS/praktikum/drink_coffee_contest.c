#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
int n=0;
int i;
int x[5];

// Membuat thread sebagai "tempat perlombaan" disini thread yang sudah digabungkan
// dapat menghabiskan cangkirnya dan apabila cangkir sudah habis fungsi akan melakukan
// return null
void *cangkir(void *arg){
    if(n==0){
        return NULL;
    }
    printf("\nPlayer %d menghabiskan 1 cangkir", i+1);
    x[i]++;
    n--;
    return NULL;
}

int main(){
// Inisialisasi berapa banyak thread yang akan digunakan pada perlombaan
// Pada perlombaan ini akan terdapat 5 thread maka kita akan inisialisasi player[5]
     pthread_t player[5];
     int tx[5];
     int temp,j,fl=0;
 
     printf("Masukkan jumlah cangkir?\n");
     scanf("%d",&n);
 
 // Disini adalah tempat kita perlombaan berlangsung
 // race-condition apabila cangkir habis pada(while) maka
 // fungsi while ini akan lanjut ke berikutnya
    while(n>0){
        for(i=0; i<5; i++){
      
      //disini setiap dijalankan fungsi ini cangkir bertambah dan 
      // ini adala tembah dibentuknya thread - thread yang digunakan sebagai
      // "Cangkir - cangkir yang dihabiskan oleh 5 player"
      
      //tx adalah temporary x yang digunakan nanti sebagai bantuan sortingan
        tx[i]=i+1;
        pthread_create(&player[i], NULL, (void *) &cangkir, (void *) &i);
        }
    }
 
 // Ini adalah fungsi dimana digabungkannya thread
    for(i=0; i<5; i++){
        pthread_join(player[i], NULL);
    }
 
    printf("\n");
 
    for(i=0; i<5; i++){
        printf("\nPlayer %d menghabiskan %d cangkir", i+1, x[i]);
    }

// Sorting pada jumlah cangkir untuk mendapatkan pemenangnya
    for(i=0; i<5; i++){
        for(j=0;j<5;j++){
            if(x[i]>x[j]){
                temp = x[i];
                x[i] = x[j];
                x [j] = temp;
                
                temp = tx[i];
                tx[i] = tx[j];
                tx [j] = temp;
            }
        }
    }

printf("\n");

// Melakukan output pemenang 1 - 3
    i=1;
    for(j=0; j<3; j++){
        printf("\nJuara %d adalah Player %d dengan jumlah cangkir: %d",i, tx[j],x[j]);
    if(x[j]>x[j+1]){
        i++;
        }
    }

return 0;
}