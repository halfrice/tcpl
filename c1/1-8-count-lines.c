#include <stdio.h>

// Exercise 1-8. Write a program to count blanks, tabs, and newlines.

int main()
{
  int c, blanks, tabs, lines;
  blanks = 0;
  tabs = 0;
  lines = 0;
  while ((c = getchar()) != EOF)
    if (c == ' ')
      ++blanks;
    else if (c == '\t')
      ++tabs;
    else if (c == '\n')
      ++lines;
  printf("Blanks: %d\n", blanks);
  printf("Tabs: %d\n", tabs);
  printf("Lines: %d\n", lines);
}
