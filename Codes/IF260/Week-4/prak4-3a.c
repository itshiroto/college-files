#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#define SHMKEY ((key_t)5678)
#define SHM_SIZE 1024
void child();
void parent();
int main() {
  pid_t pid;
  int status;
  switch (pid = fork()) {
  case -1:
    perror("fork");
    exit(1);
  case 0:
    child();
    exit(EXIT_SUCCESS);
  default:
    parent();
    waitpid(pid, &status, 0);
  }
  exit(EXIT_SUCCESS);
}
void child() {
  int i, shmid;
  char *data;
  shmid = shmget(SHMKEY, SHM_SIZE, 0644 | IPC_CREAT);
  data = (char *)shmat(shmid, (void *)0, 0);
  for (i = 0; i < 5; i++) {
    sprintf(data, "i=%d\n", i);
    sleep(2);
  }
  shmdt(data);
}
void parent() {
  int i, shmid;
  char *data;
  shmid = shmget(SHMKEY, SHM_SIZE, 0644 | IPC_CREAT);
  data = (char *)shmat(shmid, (void *)0, 0);
  for (i = 0; i < 5; i++) {
    printf("\tParent: %s", data);
    sleep(1);
  }
  shmdt(data);
}
