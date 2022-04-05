#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Nasabah {
    char nama[50];
    int totalTransaksi;
    int umur;
} Nasabah;

int main() {
    Nasabah db[50];

    // Buatlah suatu algoritma yang membaca file input.txt
    // dan menyimpan data nasabah ke dalam array db
    // dengan delimiter "#%$@*&"

    FILE *fp = fopen("input.txt", "r");
    if (fp == NULL) {
        printf("File tidak dapat dibuka\n");
        return 1;
    }
    int *token;
    char line[100];
    int i = 0;
    while (fgets(line, 100, fp) != NULL) {
        token = strtok(line, "#%$@*&");
        strcpy(db[i].nama, token);
        token = strtok(NULL, "#%$@*&");
        db[i].totalTransaksi = atoi(token);
        token = strtok(NULL, "#%$@*&");
        db[i].umur = atoi(token);
        i++;
    }

    FILE *fp2 = fopen("output.txt", "w");
    if (fp2 == NULL) {
        printf("File tidak ditemukan\n");
        return 1;
    }
    for (int i = 0; i < count; i++) {
        fprintf(fp2, "Name: %s\n", db[i].nama);
        fprintf(fp2, "Total Transaksi: %d\n", db[i].totalTransaksi);
        fprintf(fp2, "Umur: %d\n", db[i].umur);
        fprintf(fp2, "==========================\n");
    }

    fclose(fp);
    fclose(fp2);

    return 0;
}
