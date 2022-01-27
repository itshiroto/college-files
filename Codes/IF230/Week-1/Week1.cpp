#include <iostream>
using namespace std;

// int main() {
//   int data[25];
//   int i;
//   for (i = 0; i < 5; i++) {
//     cout << "Input data ke-" << i + 1 << " : ";
//     cin >> data[i];
//   }

//   for (i = 0; i < 5; i++) {
//     cout << data[i] << " ";
//   }
//   return 0;
// }

// int main() {
//   int *a;
//   int b = 10;
//   a = &b;
//   printf("%p %d\n", &b, b);
//   printf("%p %d\n", a, *a);
//   return 0;
// }

// void square(int *data) { *data = (*data) * (*data); }

// int main() {
//   int a = 2;
//   square(&a);
//   printf("%d\n", a);
//   square(&a);
//   printf("%d\n", a);

//   return 0;
// }

// int main() {
//   int *pointer;
//   int data[100];
//   int i;
//   for (i = 0; i < 20; i++) {
//     data[i] = i;
//     printf("idx %d value = %d, idx %d address = %p\n", i, data[i], i,
//     &data[i]);
//   }
//   pointer = &data[19];
//   for (i = 0; i > -20; i--) {
//     printf("idx %d value = %d, idx %d address = %p\n", i, pointer[i], i,
//            &pointer[i]);
//   }
//   return 0;
// }

void add_10(int *ptr) {
  int i, j;
  for (i = 0; i < 25; i++) {
    ptr[i] += 10;
  }
}

int main() {
  int *pointer;
  int data[10][10];
  int i, j;
  for (i = 0; i < 5; i++) {
    for (j = 0; j < 5; j++) {
      data[i][j] = i * 5 + j;
    }
  }
  add_10(&data[0][0]);

  for (i = 0; i < 5; i++) {
    for (j = 0; j < 5; j++) {
      printf("%d ", data[i][j]);
    }
    printf("\n");
  }
}
