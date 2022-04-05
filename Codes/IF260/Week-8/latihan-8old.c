// Rivo Juicer Wowor
// 00000059635

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *increment() {
  int *x;
  x = (int *)malloc(sizeof(int));
  int i;
  for (i = 0; i < 10; i++) {
    x[0] += 1;
    x[1] += 2;
  }
  return x;
}

char *tukar() {
  char *a, *b, *c;
  a = (char *)malloc(sizeof(char) * 50);
  b = (char *)malloc(sizeof(char) * 50);
  c = (char *)malloc(sizeof(char) * 50);

  strcpy(a, "string a");
  strcpy(b, "string b");

  printf("\nBefore :\n");
  printf("a = %s\n", a);
  printf("b = %s\n", b);

  c = b;
  b = a;
  a = c;

  printf("\nAfter :\n");
  printf("a = %s\n", a);
  printf("b = %s\n", b);

  free(a);
  free(b);
  free(c);

  return c;
}

int main() {
  int *x;
  char *y;
  x = increment();
  printf("x0 = %d\n", x[0]);
  printf("x1 = %d\n", x[1]);
  y = tukar();
  printf("%s\n", y);
  getchar();
  return 0;
}
