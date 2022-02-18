#include <malloc.h>
#include <stdio.h>

struct element {
  int value;
  struct element *next;
  struct element *prev;
};

struct element *create_new_node(int value) {
  struct element *node;
  node = (struct element *)malloc(sizeof(struct element));
  node->value = value;
  node->prev = node->next = NULL;
  return node;
}

void add_element_in_front_of_head(struct element **head, struct element **tail,
                                  int value) {
  struct element *node;
  node = create_new_node(value);
  if ((*head) == NULL) {
    *head = *tail = node;
  } else {
    node->next = (*head);
    node->prev = (*head)->prev;
    (*head)->prev = node;
    (*head) = node;
  }
}

void print(struct element *head) {
  struct element *curr;
  curr = head;
  while (curr) {
    printf("%d", curr->value);
    curr = curr->next;
  }
  printf("\n");
}

int main() {
  struct element *head, *tail, *curr;
  head = tail = curr = NULL;

  int value;
  while (scanf("%d", &value) == 1) {
    add_element_in_front_of_head(&head, &tail, value);
  }
  print(head);
}
