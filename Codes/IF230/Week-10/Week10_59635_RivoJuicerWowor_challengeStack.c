#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char bracket[3][2] = {{'(', ')'}, {'{', '}'}, {'[', ']'}};

typedef struct Node {
  char n;
  struct Node *next;
} Node;

void push(Node **stack, char bracket) {
  Node *new_node = (Node *)malloc(sizeof(Node));
  new_node->n = bracket;
  new_node->next = *stack;
  *stack = new_node;
}

char pop(Node **stack) {
  if (*stack == NULL) {
    return '\0';
  }
  Node *temp = *stack;
  *stack = (*stack)->next;
  char bracket = temp->n;
  free(temp);
  return bracket;
}

bool isBracketPair(char left, char right) {
  for (int i = 0; i < 3; i++) {
    if (bracket[i][0] == left && bracket[i][1] == right) {
      return true;
    }
  }
  return false;
}

int checkValidCharacter(char c) {
  for (int i = 0; i < 3; i++) {
    if (bracket[i][0] == c) {
      return 1;
    } else if (bracket[i][1] == c) {
      return 2;
    } else if (c == ' ') {
      return 0;
    }
  }
  return -1;
}

bool checkIfBracketsBalanced(char *str) {
  Node *stack = NULL;
  int isValid = 0;
  for (int i = 0; str[i] != '\n'; i++) {
    isValid = checkValidCharacter(str[i]);
    if (isValid == 1) {
      push(&stack, str[i]);
    } else if (isValid == 2) {
      if (!isBracketPair(pop(&stack), str[i])) {
        return false;
      }
    } else if (isValid == 0) {
      continue;
    } else {
      return false;
    }
  }

  return stack == NULL;
}

int main() {
  char buffer[100];
  while (1) {
    printf("Masukkan pola: ");
    fgets(buffer, sizeof(buffer), stdin);

    if (strncmp("-1", buffer, 2) == 0) {
      break;
    }
    if (checkIfBracketsBalanced(buffer)) {
      printf("Valid parentheses expression\n");
    } else {
      printf("Invalid parentheses expression\n");
    }
    printf("\n");
  }
  return 0;
}
