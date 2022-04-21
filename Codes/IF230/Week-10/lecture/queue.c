#include <stdio.h>
#include <stdlib.h>

struct element {
  int data;
  struct element *next;
};

void enqueue(int data, struct element **queue_tail,
             struct element **queue_head) {
  struct element *node = (struct element *)malloc(sizeof(struct element));
  node->data = data;
  if (*queue_head != NULL) {
    *queue_head = *queue_tail = node;
  } else {
    (*queue_tail)->next = node;
  }
}

void dequeue(struct element **queue_head) {
  if (*queue_head != NULL) {
    printf("Element popped: %d\n", (*queue_head)->data);
    struct element *node = *queue_head;
    *queue_head = (*queue_head)->next;
    free(node);
  } else {
    printf("The queue is empty.\n");
  }
}

void front(struct element *queue_head) {
  if (queue_head != NULL) {
    printf("Element on top: %d\n", queue_head->data);
  } else {
    printf("The queue is empty.\n");
  }
}
