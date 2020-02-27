#include <stdio.h>

// Exercise 1-17. Write a program to print all input lines that are
// longer than 80 characters.

#define MAXLINE 1000
#define LIMIT 80

int xgetline(char line[], int maxline);
void copyAtIndex(char to[], char from[], int index);
void copy(char to[], char from[]);

int main() {
  int len;
  int limit;
  int index;
  char line[MAXLINE];
  char lines[MAXLINE * MAXLINE];
  char longest[MAXLINE];

  limit = 80;
  index = 0;
  while ((len = xgetline(line, MAXLINE)) > 0) {
    if (len >= LIMIT) {
      copyAtIndex(lines, line, index);
      index += len;
    }
  }
  printf("\nLines longer than 80 characters:\n");
  printf("%s", lines);
  return 0;
}

int xgetline(char s[], int lim) {
  int c, i;

  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
    s[i] = c;
  }
  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return i;
}

void copyAtIndex(char to[], char from[], int index) {
  int i;

  i = 0;
  while ((to[i + index] = from[i]) != '\0') ++i;
}
