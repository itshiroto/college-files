#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *left, *right;
};

int isemptytree(struct node *root) { return root == NULL ? 1 : 0; }

void searchElement(struct node *root, int data) {
  struct node *node;

  if (isemptytree(root)) {
    printf("The tree is empty\n");
    return;
  }
  if (root->data == data) {
    printf("Element is the root data\n");
    return;
  }

  node = root;
  printf("Visiting elements: \n");

  while (node->data != data && node != NULL) {
    printf("%d ", node->data);

    if (node->data > data) {
      node = node->left;
    } else {
      node = node->right;
    }
    if (node == NULL) {
      printf("\nThe element is not found\n");
      return;
    }
  }
  printf("\nThe element is found: %d\n", node->data);
}

void insertElement(struct node **root, int data) {
  struct node *current, *parent;
  struct node *node = (struct node *)malloc(sizeof(struct node));

  node->data = data;
  node->left = node->right = NULL;

  if (*root == NULL)
    *root = node;
  else {
    current = *root;
    parent = NULL;
    while (1) {
      parent = current;
      if (data < parent->data) {
        current = current->left;
        if (current == NULL) {
          parent->left = node;
          return;
        }
      } else {
        current = current->right;
        if (current == NULL) {
          parent->right = node;
          return;
        }
      }
    }
  }
}
void preorderTraversal(struct node *root) {
  if (!isemptytree(root)) {
    printf("%d\t", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
  }
}

void inorderTraversal(struct node *root) {
  if (!isemptytree(root)) {
    inorderTraversal(root->left);
    printf("%d\t", root->data);
    inorderTraversal(root->right);
  }
}

void postorderTraversal(struct node *root) {
  if (!isemptytree(root)) {
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d\t", root->data);
  }
}

int main() {
  struct node *root = NULL;
  insertElement(&root, 10);
  insertElement(&root, 8);
  insertElement(&root, 15);
  insertElement(&root, 26);
  insertElement(&root, 4);
  insertElement(&root, 29);
  insertElement(&root, 17);
  insertElement(&root, 12);
  printf("preorderTraversal: \n");
  preorderTraversal(root);
  printf("\n");
  printf("inorderTraversal: \n");
  inorderTraversal(root);
  printf("\n");
  printf("postorderTraversal: \n");
  postorderTraversal(root);
  printf("\n");
  searchElement(root, 34);
}
