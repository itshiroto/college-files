#include <stdio.h>

struct Mahasiswa {
  char name[100];
  char nim[12];
};

enum kelas { a = 1, b, c, d, e };
int main() {
  FILE *student_file;
  FILE *new_file;

  student_file = fopen("student_data.txt", "r");
  new_file = fopen("student_new.txt", "w");

  if (student_file == NULL) {
    printf("File doesn't exist\n");
  }
  int counter = 1;

  while (!feof(student_file)) {
    struct Mahasiswa buffer;
    fscanf(student_file, "%[^,], %s %*[\n]", buffer.name, buffer.nim);
    printf("Line %d: \n", counter++);
    printf("Nama: %s \n", buffer.name);
    printf("NIM: %s \n", buffer.nim);
    printf("-------------\n");
    fprintf(new_file, "Line %d: %s %s\n", counter, buffer.name, buffer.nim);
  }

  fclose(student_file);
  fclose(new_file);
  return 0;
}
