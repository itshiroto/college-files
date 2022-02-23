#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>
char ss[100];
int main() {
  int msqid;
  key_t key = 4444;
  if ((msqid = msgget(key, 0644 | IPC_CREAT)) == -1) {
    perror("msgget");
    exit(1);
  }
  printf("Enter lines of text, ^D to quit:\n");
  while (fgets(ss, 100, stdin) && !feof(stdin)) {
    if (msgsnd(msqid, (char *)ss, 100, 0) == -1)
      perror("msgsnd");
  }
  if (msgctl(msqid, IPC_RMID, NULL) == -1) {
    perror("msgctl");
    exit(1);
  }
  return 0;
}
