#include <stdio.h>
#include <stdlib.h>

typedef struct data {
  int n;
  struct data *next;
} DATA;

void push(DATA **stack, int angka);
void pop(DATA **stack);
int isempty(DATA *stack);
int top(DATA *stack);

int main(int argc, char *argv[]) {
  // DATA *stack = NULL;
  // int n, angka;

  // printf("Masukkan jumlah data: ");
  // scanf("%d", &n); getchar();
  // int i;
  // for (i=0; i < n; i++) {
  //   printf("Masukkan data ke-%d: ", i+1);
  //   scanf("%d", &angka); getchar();
  //   push(&stack, angka);
  // }

  // while(!isempty(stack)) {
  //   printf("%d ", top(stack));
  //   pop(&stack);
  // }

  DATA *stack = NULL; // Stack perlu diinisialisasi dengan NULL agar tidak
                      // terjadi segfault.
  int number;

  while (1) {
    scanf("%d", &number);

    if (number == 0) {
      break;
    } else if (number < 0) {
      if (!isempty(stack)) {
        pop(&stack);
      }
    } else {
      push(&stack, number);
    }
  }

  // Print semua isi dari stacknya agar kita tahu isi dari stack tersebut
  // setelah diberi input
  while (!isempty(stack)) {
    printf("%d ", top(stack));
    pop(&stack);
  }

  return 0;
}

void push(DATA **stack, int angka) {
  DATA *node = (DATA *)malloc(sizeof(DATA));
  node->n = angka;
  node->next = NULL;
  if (!isempty(*stack)) {
    node->next = *stack;
  }
  *stack = node;
}

void pop(DATA **stack) {
  DATA *node = *stack;
  *stack = (*stack)->next;
  free(node);
}

int isempty(DATA *stack) { return stack == NULL ? 1 : 0; }

int top(DATA *stack) { return stack->n; }
