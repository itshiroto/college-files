#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>

struct tnode {
  int data;
  struct tnode *next;
};

int main(int argc, char const *argv[]) {
  int bil, n, inp = 1;
  struct tnode *head, *node, *tail, *curr;

  head = NULL;

  printf("Masukkan jumlah data: ");
  scanf("%d", &n);

  while (n > 0) {
    printf("Masukkan bil: ");
    scanf("%d", &bil);

    node = (struct tnode *)malloc(sizeof(struct tnode));

    node->data = bil;

    if (head == NULL) {
      head = tail = node;
      tail->next = head->next = NULL;
    } else {
      tail->next = node;
      tail = node;
      tail->next = head;
    }
    n--;
  }

  curr = head;

  while (1) {
    printf("%d\n", curr->data);
    printf("1. Maju\n");
    printf("2. Keluar\n");
    printf("Pilihan: ");
    scanf("%d", &inp);

    switch (inp) {
    case 1:
      system("clear");
      curr = curr->next;
      break;

    default:
      return 0;
    }
  }
}
