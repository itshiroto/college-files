#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
int main(int argc, char *argv[]) {
  int shmid;
  if (argc != 2) {
    fprintf(stderr, "usage: %s <shmid>\n", argv[0]);
    exit(1);
  }
  shmid = atoi(argv[1]);
  shmctl(shmid, IPC_RMID, (struct shmid_ds *)0);
  return 0;
}
