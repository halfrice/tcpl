#include <stdio.h>

// Exercise 1-6. Verify that the expression getchar() != EOF is 0 or 1.

int main()
{
  int c;
  while ((c = getchar()) != EOF)
    printf("Char code: %d, EOF = %d\n", c, c != EOF);
}
