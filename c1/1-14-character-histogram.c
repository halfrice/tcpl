#include <stdio.h>

// Exercise 1-14. Write a program to print a histogram of the frequencies of
// different characters in its input.

#define MAXCHARS 95  // Range of valid ASCII chars
#define OFFSET 32    // First valid char ASCII value

int main() {
  int i, c;
  int histogram[MAXCHARS];

  // Populate histogram with default values
  for (i = 0; i < MAXCHARS; ++i) histogram[i] = -1;

  // Calculate character frequency
  while ((c = getchar()) != EOF) {
    if (c >= 32 && c <= 127) {
      i = c - OFFSET;
      if (histogram[i] == -1)
        histogram[i] = 1;
      else if (histogram[i] >= 1)
        ++histogram[i];
    }
  }

  // Display histogram
  for (i = 0; i < MAXCHARS; ++i) {
    if (histogram[i] > 0) {
      printf("Char: %c, Freq: %d\n", 32 + i, histogram[i]);
    }
  }
}
