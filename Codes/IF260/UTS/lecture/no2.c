#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
int main() {
  int x = 100;
  int y = 50;
  int i, z;
  if (fork() == 0) {
    for (i = 0; i < 20; i++) {
      x++;
      printf("Child = %d\n", i);
    }
  } else {
    for (i = 0; i < 20; i++) {
      y++;
      printf("Parent = %d\n", i);
    }
  }
  printf("z = %d\n", x + y);
  return 0;
}
