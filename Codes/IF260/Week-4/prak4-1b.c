#include <errno.h>
#include <fcntl.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>
int main() {
  int fd;
  int len;
  char buf[PIPE_BUF];
  time_t tp;

  if ((fd = open("fifo1", O_WRONLY)) < 0) {
    perror("open");
    exit(EXIT_FAILURE);
  }

  while (1) {
    time(&tp); // ambil waktu
    len = sprintf(buf, "Dikirim oleh PID=%d Jam:%s", getpid(), ctime(&tp));
    if ((write(fd, buf, len + 1)) < 0) {
      perror("write");
      // close(fd);
      exit(EXIT_FAILURE);
    }
    sleep(3);
  }

  // close(fd);
  exit(EXIT_SUCCESS);
}
