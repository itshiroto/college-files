#include <fcntl.h>
#include <semaphore.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <unistd.h>

#define N 5
#define THINKING 0
#define HUNGRY 1
#define EATING 2
typedef struct SHM_STRUCT {
  int state[N];
  int flag;
} SHM_STRUCT;

sem_t *monitor;
SHM_STRUCT *data;

void sigint_handler(int sig) {
  sem_close(monitor);
  sem_unlink("JAWAB2-MONITOR");
  exit(0);
}

int main() {
  key_t key = 4879;
  int shmid;
  shmid = shmget(key, sizeof(int) * N, 0666 | IPC_CREAT);
  data = shmat(shmid, NULL, 0);
  monitor = sem_open("/JAWAB2-MONITOR", O_CREAT, 0644, 0);
  if (signal(SIGINT, sigint_handler) == SIG_ERR) {
    perror("SIGQUIT");
    exit(1);
  }

  while (1) {
    sem_wait(monitor);
    for (int i = 0; i < N; i++) {
      switch (data->state[i]) {
      case THINKING:
        printf("Phil%d = THINKING, ", i);
        break;
      case HUNGRY:
        printf("Phil%d = HUNGRY, ", i);
        break;
      case EATING:
        printf("Phil%d = EATING, ", i);
        break;
      }
    }
    printf("\n");
  }
}
