#include <fcntl.h>
#include <semaphore.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#define TRUE 1
#define FALSE 0

struct SHM_SIZE {
  char str[512];
  int flag, readcount;
};

int EXIT;
sem_t *readermutex, *resourcemutex;
void sigint_handler(int sig);

int main() {
  int shmid;
  int i, j;
  char ss[512], str[512];
  key_t key;
  struct SHM_SIZE *ptr;
  EXIT = FALSE;
  key = 1053;

  if (signal(SIGINT, sigint_handler) == SIG_ERR) {
    perror("SIGQUIT");
    exit(1);
  }

  readermutex = sem_open("PRAK5-3READ", O_CREAT, 0644, 1);
  if (readermutex == SEM_FAILED) {
    perror("unable to create semaphore");
    sem_unlink("PRAK5-3READ");
    exit(-1);
  }

  resourcemutex = sem_open("PRAK5-3RESC", O_CREAT, 0644, 1);
  if (resourcemutex == SEM_FAILED) {
    perror("unable to create semaphore");
    sem_unlink("PRAK5-3RESC");
    exit(-1);
  }

  shmid = shmget(key, sizeof(struct SHM_SIZE), IPC_CREAT | 0644);
  if (shmid < 0) {
    perror("failure in shmget");
    exit(-1);
  }
  ptr = shmat(shmid, NULL, 0);

  while (EXIT == FALSE) {
    sem_wait(resourcemutex);
    if (ptr->flag != 0) {
      usleep(1000);
      continue;
    } else {
      printf("Reading %s\n", ptr->str);
      ptr->flag = 0;
    }
    sem_post(resourcemutex);
  }

  return 0;
}

void sigint_handler(int sig) {
  EXIT = TRUE;
  sem_close(readermutex);
  sem_close(resourcemutex);
  sem_unlink("PRAK5-3READ");
  sem_unlink("PRAK5-3RESC");
  exit(0);
}
