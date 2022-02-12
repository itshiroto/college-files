#include <malloc.h>
#include <stdio.h>

struct list {
  int data;

  struct list *next;
};

void addNode(int data, struct list **head) {
  struct list *node = (struct list *)malloc(sizeof(struct list));
  node->data = data;

  node->next = *head;
  *head = node;
}

void printNode(struct list *head) {
  while (head != NULL) {
    printf("Data: %i\n", head->data);
    head = head->next;
  }
}

void clearNode(struct list *head) {
  struct list *temp = (struct list *)malloc(sizeof(struct list));
  while (head != NULL) {
    temp = head;
    head = temp->next;
    temp->next = NULL;
    free(temp);
  }
}

int main(int argc, char const *argv[]) {
  struct list *head = NULL;
  addNode(1, &head);
  addNode(2, &head);
  addNode(3, &head);

  printNode(head);
  clearNode(head);

  return 0;
}
