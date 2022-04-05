#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node *next, *prev;
} Node;

void addNodePrev(Node **curr, int data) {
  Node *node = (Node *)malloc(sizeof(Node));
  node->data = data;
  if (*curr == NULL) {
    *curr = node;
  } else {
    node->next = *curr;
    node->prev = (*curr)->prev;
    (*curr)->prev->next = node;
    (*curr)->prev = node;
  }
}
