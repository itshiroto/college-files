#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>
char ss[100];
int main() {
  int msqid;
  int i;
  key_t key = 4444;
  if ((msqid = msgget(key, 0644 | IPC_CREAT)) == -1) {
    perror("msgget");
    exit(1);
  }
  printf("Ready to receive messages...\n");
  for (;;) {
    if (msgrcv(msqid, (char *)ss, 100, 0, 0) == -1) {
      perror("msgrcv");
      exit(1);
    }
    for (i = 0; i < 100; i++)
      if (ss[i] == '\n')
        ss[i] = 0;
    printf("\"%s\"\n", ss);
  }
  return 0;
}
