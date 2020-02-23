#include <stdio.h>

// Exercise 1-16. Revise the main routine of the longest-line program so it will
// correctly print the length of arbitrarily long input lines, and as much as
// possible of the text.

#define MAXLINE 1000

int xgetline(char line[], int maxline);
void copy(char to[], char from[]);

int main() {
  int len;
  int max;
  char line[MAXLINE];
  char longest[MAXLINE]; 

  max = 0;
  while ((len = xgetline(line, MAXLINE)) > 0) {
    if (len > max) {
      max = len;
      copy(longest, line);
    }
  }
  if (max > 0) { 
    printf("Longest Line:\n");
    printf("- Length: %d\n", max-1);
    printf("- Line: %s", longest);
  }
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

void copy(char to[], char from[]) {
  int i;

  i = 0;
  while ((to[i] = from[i]) != '\0') ++i;
}
