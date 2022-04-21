#include <stdio.h>
#include <stdlib.h>

struct element {
  int data;
  struct element *next;
};

void push(int data, struct element **stack) {
  struct element *node = (struct element *)malloc(sizeof(struct element));
  node->data = data;
  node->next = *stack;
  (*stack) = node;
}

void pop(struct element **stack) {
  if (*stack != NULL) {
    printf("Element popped: %d\n", (*stack)->data);
    struct element *node = *stack;
    *stack = (*stack)->next;
    free(node);
  } else {
    printf("The stack is empty.\n");
  }
}

void top(struct element *stack) {
  if (stack != NULL) {
    printf("Element on Top: %d", stack->data);
  } else {
    printf("Stack is empty\n");
  }
}
