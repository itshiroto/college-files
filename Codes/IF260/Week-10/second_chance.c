#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pageTable {
  int pgNum;
  bool rbit;
} pageTable;

typedef struct Node {
  pageTable data;
  struct Node *next;
} Node;

int pageFault = 0;

void enqueue(Node **head, Node **tail, pageTable data) {
  Node *node = (Node *)malloc(sizeof(Node));
  node->data = data;
  node->next = NULL;
  if (*head == NULL) {
    *head = *tail = node;
  } else {
    (*tail)->next = node;
    *tail = node;
  }
  pageFault++;
}

void dequeue(Node **head, Node **tail, int pgNum) {
  if (*head == NULL) {
    return;
  }
  Node *curr = (*head);
  Node *prev = NULL;
  while (curr != NULL) {
    if (curr->data.rbit == false) {
      Node *temp = curr;
      if (prev != NULL) {
        prev->next = curr->next;
      } else {
        *head = curr->next;
      }
      if (curr->next == NULL) {
        *tail = prev;
      }
      free(temp);
      return;
    }
    curr->data.rbit = false;
    prev = curr;
    curr = curr->next;
  }
}

bool checkIfExists(Node **head, int pgNum) {
  if (*head == NULL) {
    return false;
  }
  Node *curr = (*head);
  while (curr != NULL) {
    if (curr->data.pgNum == pgNum) {
      curr->data.rbit = true;
      return true;
    }
    curr = curr->next;
  }
  return false;
}

void printQueue(Node *head) {
  Node *curr = head;
  int count = 3;
  printf("PF: %d\n", pageFault);
  printf("PN\tR\n");
  while (curr != NULL) {
    printf("%d\t%d\n", curr->data.pgNum, curr->data.rbit);
    curr = curr->next;
    count--;
  }
  int i;
  for (i = 0; i < count; i++) {
    printf("X\tX\n");
  }
  printf("\n");
}

pageTable createPayload(int buffer) {
  pageTable payload;
  payload.pgNum = buffer;
  payload.rbit = false;
  return payload;
}

int main() {
  Node *head = NULL;
  Node *tail = NULL;
  bool exit = false;
  int buffer, count = 0;
  while (!exit) {
    scanf("%d", &buffer);
    if (buffer == 0) {
      break;
    }
    if (buffer < 1 || buffer > 5) {
      printf("Input tidak valid!\n");
      continue;
    }
    if (count < 3) {
      if (!checkIfExists(&head, buffer)) {
        enqueue(&head, &tail, createPayload(buffer));
        count++;
      }
    } else {
      if (!checkIfExists(&head, buffer)) {
        dequeue(&head, &tail, buffer);
        enqueue(&head, &tail, createPayload(buffer));
      }
    }
    printQueue(head);
  }
}