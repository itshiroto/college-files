#include <malloc.h>
#include <stdio.h>

struct element {
  int value;
  struct element *next;
};

int main() {
  struct element *head;
  struct element *tail;
  struct element *curr;
  struct element *node;
  head = tail = curr = NULL;
  int value;
  while (scanf("%d", &value) == 1) {
    node = (struct element *)malloc(sizeof(struct element));
    node->value = value;
    if (head == NULL) {
      head = tail = node;
      node->next = NULL;
    } else {
      node->next = head;
      head = node;
    }
  }
  curr = head;
  while (curr != NULL) {
    printf("%d ", curr->value);
    curr = curr->next;
  }
  while (curr != NULL) {
    head = head->next;
    free(curr);
  }
}
