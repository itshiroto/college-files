#include <stdio.h>
#include <stdlib.h>

typedef struct process {
  int pid, arr, cpu, io, bt, cm, tat, wt, rt;
} process;

int main() {
  int cnt;
  float avgWt, avgTat, avgRt;
  avgWt = avgTat = avgRt = 0;

  // Let user input how many tasks that will be calculated.
  scanf("%d", &cnt);

  // Create a array of process with the name of p.
  process p[cnt];
  int i;

  // Let the user input all of the paramaters desired.
  for (i = 0; i < cnt; i++) {
    scanf("%d %d %d %d", &p[i].pid, &p[i].arr, &p[i].cpu, &p[i].io);
    // While the user still inputing data, calculate the burst time.
    p[i].bt = p[i].cpu + p[i].io;
  }

  // Set the completion time to burst time, and response time to zero.
  p[0].cm = p[0].bt;
  p[0].rt = 0;

  // The first loop counts completion time and the response time
  // started with the second element.
  for (i = 1; i < cnt; i++) {
    p[i].cm = p[i - 1].cm + p[i].bt;
    p[i].rt = (p[i - 1].rt + p[i - 1].bt) - p[i].arr;
  }

  // The second loop counts turn around time and waiting time
  // started with the first element.
  for (i = 0; i < cnt; i++) {
    p[i].tat = p[i].cm - p[i].arr;
    p[i].wt = p[i].tat - p[i].bt;
  }

  // Prints the calculation
  printf("PID\tWT\tRT\tTAT\n");
  for (i = 0; i < cnt; i++) {
    printf("%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].wt, p[i].rt, p[i].tat,
           p[i].cm);
  }

  // The third for loop counts every waiting time, turn around time,
  // and response time, and accumulates that into each average variable.
  for (i = 0; i < cnt; i++) {
    avgWt += p[i].wt;
    avgTat += p[i].tat;
    avgRt += p[i].rt;
  }

  // Get the average by dividing the total of each parameters with the total
  // count of tasks. Then prints the average.
  avgWt /= cnt;
  avgTat /= cnt;
  avgRt /= cnt;
  printf("Average: %.2f %.2f %.2f\n", avgWt, avgRt, avgTat);

  return 0;
}
