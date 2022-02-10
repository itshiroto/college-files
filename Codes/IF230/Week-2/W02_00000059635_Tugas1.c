#include <stdio.h>
#include <string.h>

#define MAX_USERS 20
typedef enum { FALSE, TRUE } bool;

typedef struct {
  bool exist;
  char name[50];
  char major[35];
  float gpa;
} Student;

typedef struct {
  Student list[MAX_USERS];
  int count;
} Students;

Student addStudent() {
  Student data;
  char name[100];
  char major[100];
  float gpa;

  printf("\n\n");
  printf("  Insert Student Information  \n");
  printf("------------------------------\n");

  printf("Nama    : ");
  scanf("%[^\n]%*c", name);
  printf("Major   : ");
  scanf("%[^\n]%*c", major);
  printf("GPA     : ");
  scanf("%f", &gpa);
  fflush(stdin);

  printf("\n\n");

  strcpy(data.name, name);
  strcpy(data.major, major);
  data.gpa = gpa;
  data.exist = TRUE;

  return data;
}

int menu(int count) {
  int menu;
  printf("Welcome to simple student database (%i/20)\n", count);
  printf("1. Show all students\n");
  printf("2. Input new student\n");
  printf("3. Exit\n");
  printf("Choose: ");
  scanf("%i%*c", &menu);
  return menu;
}

void printDB(Students db) {
  if (db.count == 0) {
    printf("\n");
    printf("Data still empty\n");
    printf("\n");
    return;
  }
  printf("                  List of Student Information                 \n");
  printf("--------------------------------------------------------------\n");
  printf("|No.|           Nama           |        Major        |  GPA  |\n");
  printf("--------------------------------------------------------------\n");
  for (int i = 0; i < db.count; i++) {
    Student data = db.list[i];
    printf("|%-3i| %-25s| %-20s| %-6.2f|\n", i + 1, data.name, data.major,
           data.gpa);
  }
  printf("--------------------------------------------------------------\n");
  printf("\n\n");
}

int main() {
  Students db;
  db.count = 0;

  int keepGoing = 1;
  while (keepGoing) {
    switch (menu(db.count)) {
    case 1:
      printDB(db);
      break;
    case 2:
      if (db.count >= MAX_USERS) {
        printf("Database is full\n");
        break;
      }
      db.list[db.count] = addStudent();
      db.count++;
      break;

    case 3:
      keepGoing = 0;
      break;
    }
  }
}
