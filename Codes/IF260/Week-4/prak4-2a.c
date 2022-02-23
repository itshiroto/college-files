#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#define SHM_SIZE 1024 // 1KByte Shared Memory
int main(int argc, char *argv[]) {
  key_t key;
  int shmid, mode;
  char *data;
  if (argc > 2) {
    fprintf(stderr, "usage: .prak4-2 <data string>\n");
    exit(1);
  }
  // membuat key
  key = ftok("shmdemo.c", 'R');
  // connect ke segment memory atau create segment memory
  shmid = shmget(key, SHM_SIZE, 0644 | IPC_CREAT);
  // attach ke segment untuk mengarah pada pointer
  data = (char *)shmat(shmid, (void *)0, 0);
  // read atau modifikasi segment, berdasarkan command yang ada.
  if (argc == 2) {
    printf("write:\"%s\"\n", argv[1]);
    strncpy(data, argv[1], SHM_SIZE);
  } else {
    printf("read:\"%s\"\n", data);
  }
  // detach dari segment
  shmdt(data);
  return 0;
}
