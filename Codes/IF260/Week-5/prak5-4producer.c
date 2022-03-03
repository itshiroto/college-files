#include <fcntl.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>

struct SHM_DATA {
  char data[50];
  int flag;
};

int main() {
  key_t key = 1274;
  int shmid;
  sem_t *producerMtx, *consumerMtx;
  struct SHM_DATA *ptr;
  char ss[50];

  producerMtx = sem_open("PRAK5-4PRODUCER", O_CREAT, 0644, 1);
  if (producerMtx == SEM_FAILED) {
    perror("Semaphore error");
    sem_unlink("PRAK5-4PRODUCER");
    exit(-1);
  }

  consumerMtx = sem_open("PRAK5-4CONSUMER", O_CREAT, 0644, 0);
  if (consumerMtx == SEM_FAILED) {
    perror("Semaphore error");
    sem_unlink("PRAK5-4CONSUMER");
    exit(-1);
  }

  shmid = shmget(key, sizeof(struct SHM_DATA), IPC_CREAT | 0644);
  if (shmid < 0) {
    perror("shmget error");
    exit(-1);
  }

  ptr = shmat(shmid, NULL, 0);
  for (int i = 0; i < 10; i++) {
    if (ptr->flag != 0) {
      sem_wait(producerMtx);
    }
    printf("Ketik kalimat untuk consumer: ");
    scanf("%[^\n]", ptr->data);
    getchar();
    ptr->flag++;

    sem_post(consumerMtx);
  }
}
