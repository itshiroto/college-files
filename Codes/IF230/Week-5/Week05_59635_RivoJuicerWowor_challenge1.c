#include <ctype.h>
#include <malloc.h>
#include <stdio.h>
#include <string.h>
#define MAX_USERS 10

typedef enum { FALSE, TRUE } bool;

typedef struct {
  char nama[75];
  int tinggi;
  int berat;
} Person;

typedef struct {
  Person *data;
  int used;
} DB;

void swapPerson(Person *a, Person *b) {
  Person temp = *a;
  *a = *b;
  *b = temp;
}

void printDB(DB input) {
  for (int i = 0; i < input.used; i++) {
    Person data = input.data[i];
    printf("%-7s : %s\n", "Nama", data.nama);
    printf("%-7s : %i\n", "Tinggi", data.tinggi);
    printf("%-7s : %i\n", "Berat", data.berat);
    printf("\n");
  }
}

int mainMenu(DB input) {
  int menu;
  printDB(input);
  printf("---------------------------\n"
         "    NESTED SORT EXAMPLE    \n"
         "---------------------------\n");
  printf("1. Insert Data\n"
         "2. Bubble Sort\n"
         "3. Selection Sort\n"
         "4. Insertion Sort\n"
         "5. Exit\n"
         "Your choice: ");
  scanf("%d%*c", &menu);
  return menu;
}

void bubbleSort(Person **input, int n) {
  char choice;
  printf("Sort ascending (a) or descending (d)? ");
  scanf("%c%*c", &choice);
  choice = tolower(choice);

  for (int i = 0; i < n; i++) {
    for (int j = i; j < n - 1; j++) {
      Person *curr = &(*input)[j];
      Person *next = &(*input)[j + 1];

      if (choice == 'a') {
        if (strcmp(curr->nama, next->nama) > 0) {
          swapPerson(curr, next);
        } else if (strcmp(curr->nama, next->nama) == 0) {
          if (curr->tinggi > next->tinggi) {
            swapPerson(curr, next);
          } else if (curr->tinggi == next->tinggi) {
            if (curr->berat > next->berat) {
              swapPerson(curr, next);
            }
          }
        }
      } else if (choice == 'd') {
        if (strcmp(curr->nama, next->nama) < 0) {
          swapPerson(curr, next);
        } else if (strcmp(curr->nama, next->nama) == 0) {
          if (curr->tinggi < next->tinggi) {
            swapPerson(curr, next);
          } else if (curr->tinggi == next->tinggi) {
            if (curr->berat < next->berat) {
              swapPerson(curr, next);
            }
          }
        }
      }
    }
  }
}

void addData(DB *inputDB) {
  Person input;
  printf("%-7s : ", "Nama");
  scanf("%[^\n]", input.nama);
  printf("%-7s : ", "Tinggi");
  scanf("%i", &input.tinggi);
  printf("%-7s : ", "Berat");
  scanf("%i", &input.berat);

  inputDB->data[inputDB->used] = input;
  inputDB->used++;
  printf("---------------------------\n"
         "\n");
}

// void input

int main() {
  DB inputDB;
  inputDB.data = (Person *)malloc(sizeof(Person) * MAX_USERS);
  inputDB.used = 0;

  bool keepGoing = TRUE;
  while (keepGoing) {
    switch (mainMenu(inputDB)) {
    case 1:
      addData(&inputDB);
      break;
    case 2:
      bubbleSort(&inputDB.data, inputDB.used);
      break;
    case 3:
      break;
    case 4:
      break;
    case 5:
      keepGoing = FALSE;
      break;
    }
  }
}
