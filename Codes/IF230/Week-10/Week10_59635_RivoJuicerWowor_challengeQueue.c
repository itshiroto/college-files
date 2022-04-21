#include <stdio.h>
#include <stdlib.h>

typedef struct data {
  int n;
  struct data *next;
} Data;

void enqueue(Data **head, Data **tail, int n) {
  Data *node = (Data *)malloc(sizeof(Data));
  node->n = n;
  node->next = NULL;
  if (*head == NULL) {
    *head = *tail = node;
  } else {
    (*tail)->next = node;
    *tail = node;
  }
}

void dequeue(Data **head) {
  if (*head == NULL) {
    return;
  }
  Data *temp = *head;
  *head = (*head)->next;
  free(temp);
}

int front(Data *head) {
  if (head == NULL) {
    return -1;
  }
  return head->n;
}

void printQueue(Data *head) {
  while (head != NULL) {
    printf("%d ", head->n);
    head = head->next;
  }
  printf("\n\n");
}

int main() {
  Data *head, *tail;
  head = tail = NULL;
  int number;
  int dequeueCount = 0;

  while (1) {
    if (dequeueCount > 0) {
      printf("Terdapat %d iterasi yang ada dalam kuota dequeue.\n",
             dequeueCount);
    }
    printf("Masukkan angka: ");
    scanf("%d", &number);
    if (number < 0) {
      break;
    }
    if (front(head) == -1 || number >= front(head)) {
      int iteration = front(head) == -1 ? number : front(head);
      if (dequeueCount > 0) {
        iteration -= dequeueCount;
        dequeueCount -= number;
      }
      for (int i = 0; i < iteration; i++) {
        enqueue(&head, &tail, number);
      }
      printf("Angka yang berhasil dienqueue sebanyak %d kali: ", iteration);
    } else {
      for (int i = 0; i < number; i++) {
        if (front(head) != -1) {
          dequeue(&head);
        } else {
          dequeueCount++;
        }
      }
      printf("Angka yang berhasil didequeue sebanyak %d kali: ", number);
    }
    printQueue(head);
  }
}