#include <fcntl.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  int i;
  sem_t *mutex = sem_open("/PRAK5-1TEST", O_CREAT, 0660, 1);
  if (mutex == SEM_FAILED) {
    perror("sem_open()");
    exit(1);
  }
  for (i = 0; i < 10; i++) {
    printf("Tekan enter: ");
    getchar();
    sem_post(mutex);
  }
  sem_close(mutex);
  return 0;
}
