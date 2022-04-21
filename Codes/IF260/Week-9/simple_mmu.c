/*
  Nama  : Rivo Juicer Wowor
  NIM   : 00000059635

  Catatan: Ketika dicompile, mohon menambahan argumen `-lm`
           Ex. gcc -lm simple_mmu.c -o simple_mmu
*/

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define PAGE_SIZE 16

typedef struct pageTable {
  int resident;
  char frame[4];
} pageTable;

pageTable simple_mmu[PAGE_SIZE];

pageTable createNewRow(char *frame, bool res) {
  pageTable input;
  strcpy(input.frame, frame);
  input.resident = res;
  return input;
}

char *addPaddingInBinary(char *bin) {
  int i = 0, j = 0;
  char *result = malloc(sizeof(char) * 50);
  while (i < strlen(bin)) {
    if (i % 4 == 0 && i != 0) {
      result[j++] = ' ';
    }
    result[j++] = bin[i++];
  }
  result[j++] = '\0';
  return result;
}

char *reverseStr(const char *str) {
  int len = strlen(str);
  char *newStr = malloc(len + 1);
  for (int i = 0; i < len; i++) {
    newStr[i] = str[len - i - 1];
  }
  newStr[len] = '\0';
  return newStr;
}

char *intToBinary(unsigned long num) {
  char binary[50];
  int i = 0;
  // while (num > 0) {
  //   binary[i++] = (num % 2) + '0';
  //   num /= 2;
  // }
  for (i = 0; i < 32; i++) {
    binary[i] = (num % 2) + '0';
    num /= 2;
  }
  while ((i % 4) != 0) {
    binary[i++] = '0';
  }
  binary[i++] = '\0';
  return reverseStr(binary);
}

int binaryToInt(char *input) {
  long num = 0;
  int len = strlen(input);
  for (int i = 0; i < len; i++) {
    num += (input[i] - '0') * pow(2, len - i - 1);
  }
  return num;
}

void initPage() {
  simple_mmu[0] = createNewRow("1110", true);
  simple_mmu[1] = createNewRow("\0", false);
  simple_mmu[2] = createNewRow("0001", true);
  simple_mmu[3] = createNewRow("1010", true);
  simple_mmu[4] = createNewRow("0100", true);
  simple_mmu[5] = createNewRow("0011", true);
  simple_mmu[6] = createNewRow("\0", false);
  simple_mmu[7] = createNewRow("\0", false);
  simple_mmu[8] = createNewRow("\0", false);
  simple_mmu[9] = createNewRow("0101", true);
  simple_mmu[10] = createNewRow("\0", false);
  simple_mmu[11] = createNewRow("0111", true);
  simple_mmu[12] = createNewRow("\0", false);
  simple_mmu[13] = createNewRow("\0", false);
  simple_mmu[14] = createNewRow("1100", true);
  simple_mmu[15] = createNewRow("\0", false);
}

int doTranslation(unsigned long input) {
  char *binary = intToBinary(input);
  char pageNum[5], data[32], result[32];
  strncpy(pageNum, binary, 4);
  strncat(data, binary + 4, 28);
  int findPageNum = binaryToInt(pageNum);

  // printf("%s\n", binary);
  // printf("%s/%i\n", pageNum, findPageNum);
  // printf("binary: %s\n", binary);
  // printf("data: %s\n", data);
  // printf("pageNum: %s\n", pageNum);

  for (int i = 0; i < PAGE_SIZE; i++) {
    // printf("%s and %s\n", pageNum, simple_mmu[i].frame);
    if (findPageNum == i) {
      if (simple_mmu[i].resident) {
        // printf("Found!\n");
        strcat(result, simple_mmu[i].frame);
        strcat(result, data);
        printf("%s (0x%lX)\n", addPaddingInBinary(result), binaryToInt(result));
        return 0;
      } else {
        printf("PAGE FAULT!\n");
        return -1;
      }
    }
  }
}

int main() {
  unsigned long buffer;
  initPage();
  printf("0x");
  scanf("%lx", &buffer);
  doTranslation(buffer);
}