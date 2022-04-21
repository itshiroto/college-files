#include <stdio.h>
#include <stdlib.h>

typedef struct data {
  int n;
  struct data *next;
} DATA;

// void enqueue(DATA **head, DATA **tail, int angka);
void enqueue(DATA **head, int angka);
void dequeue(DATA **head);
int isempty(DATA *head);
int front(DATA *head);

int main(int argc, char *argv[]) {
  // DATA *head, *tail;
  // int n, angka;
  DATA *head = NULL;
  int number;

  // head = tail = NULL;
  // printf("Masukkan jumlah data: ");
  // scanf("%d", &n);
  // getchar();

  // int i;
  // for (i = 0; i < n; i++) {
  //   printf("Masukkan data ke-%d: ", i + 1);
  //   scanf("%d", &angka);
  //   getchar();
  //   enqueue(&head, &tail, angka);
  // }

  while (1) {
    scanf("%d", &number);
    if (number == 0) {
      break;
    } else if (number < 0) {
      if (!isempty(head)) {
        dequeue(&head);
      }
    } else {
      enqueue(&head, number);
    }
  }

  while (!isempty(head)) {
    printf("%d ", front(head));
    dequeue(&head);
  }

  return 0;
}

// void enqueue(DATA **head, DATA **tail, int angka) {
void enqueue(DATA **head, int angka) {
  DATA *node = (DATA *)malloc(sizeof(DATA));
  node->n = angka;
  node->next = NULL;

  if (*head == NULL) {
    *head = node;
  } else {
    // (*tail)->next = node;
    DATA *temp = *head;
    while (temp->next != NULL) {
      temp = temp->next;
    }
    temp->next = node;
  }
  // *tail = node;
}

void dequeue(DATA **head) {
  DATA *node = *head;
  *head = (*head)->next;
  free(node);
}

int isempty(DATA *head) { return head == NULL ? 1 : 0; }

int front(DATA *head) { return head->n; }
