#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

struct tnode {
  int data;
  struct tnode *next, *prev;
};

int main(int argc, char const *argv[]) {
  int bil, n, inp=1;
  struct tnode *head, *node, *tail, *curr;

  head = NULL;

  printf("Masukkan jumlah data: "); scanf("%d", &n);

  while (n > 0) {
    printf("Masukkan bil: "); scanf("%d", &bil);

    node = (struct tnode*) malloc(sizeof(struct tnode));

    node->next = NULL;
    node->prev = NULL;
    node->data = bil;

    if (head == NULL) {
      head = tail = node;
    } else {
      tail->next = node;
      node->prev = tail;
      tail = node;
    }
    n--;
  }

  curr = head;

  while(1) {
    printf("%d\n", curr->data);
    printf("1. Maju\n");
    printf("2. Mundur\n");
    printf("3. Keluar\n");
    printf("Pilihan: "); scanf("%d", &inp);

    switch(inp) {
      case 1: 
        system("clear");
        if(curr->next == NULL) {
          printf("Tidak dapat maju karena node selanjutnya kosong\n");
        }
        else curr = curr->next;
        break;

      case 2:
        system("clear");
        if(curr->prev == NULL) {
          printf("Tidak dapat mundur karena node sebelumnya kosong\n");
        }
        else curr = curr->prev;
        break;

      default: return 0;
    }
  }
}
