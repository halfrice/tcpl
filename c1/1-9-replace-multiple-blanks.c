#include <stdio.h>

// Exercise 1-9. Write a program to copy its input to its output, replacing each
// string of one or more blanks by a single blank.

int main() {
  int c;
  int blank = 0;
  while ((c = getchar()) != EOF) {
    if (c == ' ') {
      if (blank == 0) {
        printf("%c", c);
        ++blank;
      }
    }
    if (c != ' ') {
      if (blank >= 1) {
        blank = 0;
      }
      printf("%c", c);
    }
  }
}
