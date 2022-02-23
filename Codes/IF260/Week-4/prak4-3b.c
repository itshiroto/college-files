#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
int main() {
  int child, shmid, key = 1000, *ptrData;
  child = fork();
  shmid = shmget(key, sizeof(int), 0644 | IPC_CREAT);
  ptrData = (int *)shmat(shmid, (void *)0, 0);
  *ptrData = 0;
  if (child == 0) {
    int i = 0;
    for (i; i < 15; i++) {
      *ptrData = *ptrData + 1;
      printf("i=%d child's ptrData=%d\n", i, *ptrData);
    }
  } else if (child > 0) {
    int i = 0;
    for (i; i < 15; i++) {
      *ptrData = *ptrData + 1;
      printf("i=%d parent's ptrData=%d\n", i, *ptrData);
    }
    int status;
    waitpid(child, &status, 0);
  }
  shmdt(ptrData);
  shmctl(shmid, IPC_RMID, (struct shmid_ds *)0);
  return 0;
}
