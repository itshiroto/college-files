#include <fcntl.h>
#include <semaphore.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#define TRUE 1
#define FALSE 0

struct SHM_SIZE {
  char str[512];
  int flag, readcount;
};

sem_t *resourcemutex;
int shmid, EXIT;
void sigint_handler(int sig);
struct SHM_SIZE *ptr;

int main() {
  char str[512], ss[512];
  key_t key;
  key = 1053;
  EXIT = FALSE;
  if (signal(SIGINT, sigint_handler) == SIG_ERR) {
    perror("SIGQUIT");
    exit(1);
  }

  resourcemutex = sem_open("PRAK5-3RESC", O_CREAT, 0644, 1);
  if (resourcemutex == SEM_FAILED) {
    perror("unable to execute semaphore");
    sem_unlink("PRAK5-3RESC");
    exit(-1);
  }

  shmid = shmget(key, sizeof(struct SHM_SIZE), IPC_CREAT | 0644);
  if (shmid < 0) {
    perror("shmget error..");
    exit(-1);
  }
  ptr = shmat(shmid, NULL, 0);
  int i = 0;
  while (EXIT == FALSE) {
    printf("Masukkan Kata/kalimat : ");
    scanf("%[^\n]", ss);
    getchar();
    sem_wait(resourcemutex);
    strcpy(ptr->str, ss);
    sem_post(resourcemutex);
    i++;
  }
  sem_close(resourcemutex);
  return 0;
}

void sigint_handler(int sig) { EXIT = TRUE; }
