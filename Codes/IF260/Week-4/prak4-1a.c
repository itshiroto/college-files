#include <errno.h>
#include <fcntl.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
  int fd; // descriptor untuk FIFO
  int len;
  char buf[PIPE_BUF];
  if ((fd = open("fifo1", O_RDONLY)) < 0) {
    perror("open");
    exit(EXIT_FAILURE);
  }
  while ((len = read(fd, buf, PIPE_BUF - 1)) > 0)
    printf("Read:  %s", buf);
  // close(fd);
  exit(EXIT_SUCCESS);
}
