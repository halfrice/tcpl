#include <stdio.h>

// Exercise 1-12. Write a program that prints its input one word per line.

#define IN 1
#define OUT 0

int main() {
  int c, state;

  state = OUT;
  while ((c = getchar()) != EOF) {
    if ((c >= 97 && c <= 122) || (c >= 65 && c <= 90) || (c >= 48 && c <= 57) ||
        c == 45) {
      state = OUT;
      printf("%c", c);
    } else if (state == OUT) {
      state = IN;
      printf("\n");
    }
  }
}
