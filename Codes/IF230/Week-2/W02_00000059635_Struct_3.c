#include <stdio.h>
#include <string.h>

struct Student {
  char name[50];
  char major[35];
  float gpa;
};

struct Student newStudent(char name[], char major[], float gpa) {
  struct Student s;
  strcpy(s.name, name);
  strcpy(s.major, major);
  s.gpa = gpa;

  return s;
}

int main() {
  struct Student waldo = newStudent("Waldo", "Informatika", 3.98);
  printf("Nama    : %s\n", waldo.name);
  printf("Major   : %s\n", waldo.major);
  printf("GPA     : %.2f\n", waldo.gpa);
  return 0;
}
