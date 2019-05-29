#include <stdio.h>

// Exercise 1-7. Write a program toprint the value of EOF.

int main()
{
  int c;
  while ((c = getchar()) != EOF)
    printf("Char code: %d, EOF = %d\n", c, c != EOF);
}
