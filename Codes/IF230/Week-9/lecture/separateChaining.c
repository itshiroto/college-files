#include <stdio.h>
#include <stdlib.h>

#define BUCKET_SIZE 15

struct node {
  int value;
  struct node *next;
};

struct node *bucket[BUCKET_SIZE];

void init() {
  int i;
  for (i = 0; i < BUCKET_SIZE; i++)
    bucket[i] = NULL;
}

void insert(int value) {
  struct node *newNode = (struct node *)malloc(sizeof(struct node));
  newNode->value = value;
  newNode->next = NULL;

  int key = value % BUCKET_SIZE;

  if (bucket[key] == NULL)
    bucket[key] = newNode;
  else {
    struct node *temp = bucket[key];
    while (temp->next) {
      temp = temp->next;
    }
    temp->next = newNode;
  }
}

void print() {
  int i;
  for (i = 0; i < BUCKET_SIZE; i++) {
    struct node *temp = bucket[i];
    printf("Bucket[%d]-->", i);
    while (temp) {
      printf("%d-->", temp->value);
      temp = temp->next;
    }
    printf("NULL\n");
  }
}

int main() {
  init();
  int i;
  for (i = 0; i < 100; i++) {
    insert(rand() % 100);
  }
  print();

  return 0;
}
