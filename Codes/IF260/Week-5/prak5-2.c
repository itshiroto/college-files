#include <errno.h>
#include <fcntl.h>
#include <pthread.h>
#include <semaphore.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
void *thread1();
void *thread2();
void sigint_handler(int sig);

int var1 = 0, var2 = 0;
sem_t *mut1, *mut2;

int main() {
  pthread_t thrd1, thrd2;
  signal(SIGINT, sigint_handler);
  mut1 = sem_open("PRAK5-2MUT1", O_CREAT, 0644, 1);
  mut2 = sem_open("PRAK5-2MUT2", O_CREAT, 0644, 1);
  pthread_create(&thrd1, NULL, thread1, NULL);
  pthread_create(&thrd2, NULL, thread2, NULL);
  pthread_join(thrd1, NULL);
  pthread_join(thrd2, NULL);
}

void *thread1() {
  int i;
  for (i = 0; i < 10; i++) {
    sem_wait(mut1);
    var1++;
    sem_post(mut2);
    printf("var1 + var2 = %d\n", var1 + var2);
    sem_wait(mut2);
    sem_post(mut1);
  }
}

void *thread2() {
  int i;
  for (i = 0; i < 10; i++) {
    sem_wait(mut2);
    var2++;
    sem_post(mut1);
    printf("var1 + var2 = %d\n", var1 + var2);
    sem_wait(mut1);
    sem_post(mut2);
  }
}

void sigint_handler(int sig) {
  sem_close(mut1);
  sem_close(mut2);
  sem_unlink("PRAK5-2MUT1");
  sem_unlink("PRAK5-2MUT2");
  exit(0);
}
