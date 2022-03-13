#include <fcntl.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <unistd.h>

#define N 5
#define LEFT (i + N - 1) % N
#define RIGHT (i + 1) % N
#define THINKING 0
#define HUNGRY 1
#define EATING 2

typedef struct SHM_STRUCT {
  int state[N];
  int flag;
} SHM_STRUCT;

int *state;
sem_t mutex, s[N], *monitor;
int shmid;
SHM_STRUCT *data;

void sigint_handler(int sig) {
  sem_close(monitor);
  sem_unlink("JAWAB2-MONITOR");
  exit(0);
}

void test(int i) {
  if (state[i] == HUNGRY && state[LEFT] != EATING && state[RIGHT] != EATING) {
    state[i] = EATING;
    sem_post(&s[i]);
  }
}

void take_forks(int i) {
  sem_wait(&mutex);
  state[i] = HUNGRY;
  test(i);
  sem_post(&mutex);
  sem_wait(&s[i]);
}

void put_forks(int i) {
  sem_wait(&mutex);
  state[i] = THINKING;
  test(LEFT);
  test(RIGHT);
  sem_post(&mutex);
}

void *philosopher(void *num) {
  while (1) {
    int *i = num;
    // usleep(5000);
    sleep(2);
    take_forks(*i);
    // usleep(5000);
    sleep(2);
    sem_post(monitor);
    put_forks(*i);
  }
}

int main() {
  int i, a[5];
  key_t key = 4879;
  pthread_t thread[N];
  shmid = shmget(key, sizeof(int) * N, IPC_CREAT | 0666);
  data = shmat(shmid, NULL, 0);
  state = data->state;
  sem_init(&mutex, 0, 1);
  monitor = sem_open("/JAWAB2-MONITOR", O_CREAT, 0644, 0);
  for (i = 0; i < N; i++) {
    sem_init(&s[i], 0, 0);
  }

  for (i = 0; i < N; i++) {
    a[i] = i;
    pthread_create(&thread[i], NULL, philosopher, (void *)&a[i]);
  }

  for (i = 0; i < N; i++) {
    pthread_join(thread[i], NULL);
  }

  return 0;
}
