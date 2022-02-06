#include <stdio.h>
struct Student {
  char name[50];
  char major[35];
  float gpa;
};

int main() {
  struct Student waldo = {"Waldo", "Informatika", 3.98};
  struct Student *waldoPtr = &waldo;

  printf("Without Pointer\n");
  printf("Nama    : %s\n", waldo.name);
  printf("Major   : %s\n", waldo.major);
  printf("GPA     : %.2f\n", waldo.gpa);

  printf("With Pointer\n");
  printf("Nama    : %s\n", waldoPtr->name);
  printf("Major   : %s\n", waldoPtr->major);
  printf("GPA     : %.2f\n", waldoPtr->gpa);

  return 0;
}
