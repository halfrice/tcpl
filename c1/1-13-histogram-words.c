#include <stdio.h>

// Exercise 1-13. Write a program to print a histogram of the lengths of words
// in its input. It is easy to draw the histogram with the bars horizontal; a
// vertical orientation is more challenging.

#define IN 1
#define OUT 0
#define MAXWORDS 25

int main() {
  int i, j, c;
  int height, state, wordlength, wordcount;
  int histogram[MAXWORDS];

  state = OUT;
  wordcount = wordlength = 0;

  // Fill histogram with default values
  for (i = 0; i < MAXWORDS; ++i) histogram[i] = -1;

  // Insert word length values into histogram
  while ((c = getchar()) != EOF) {
    if (wordcount == MAXWORDS) {
      printf("\nYou have reached the %d word limit. Gold star!", MAXWORDS);
      break;
    }
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ||
        (c >= '0' && c <= '9') || c == '-') {
      state = IN;
      ++wordlength;
    } else if ((c == ' ' || c == '\n' || c == '\t') && wordlength >= 1 &&
               state == IN) {
      state = OUT;
      histogram[wordcount] = wordlength;
      ++wordcount;
      wordlength = 0;
    } else {
      state = OUT;
    }
  }

  // Find the longest word to determine histogram height
  height = 0;
  for (i = 0; i < MAXWORDS; ++i) {
    if (histogram[i] > height) height = histogram[i];
  }

  // Create vertical histogram table
  printf("\n\n   Word Histogram\n\n");
  for (i = 0; i < height; ++i) {
    // Creates the row ledger
    if ((height - i) <= 9)
      printf(" %d|", height - i);
    else
      printf("%d|", height - i);

    // Caluclate bar heights
    for (j = 0; j < MAXWORDS; ++j) {
      if (histogram[j] + i >= height)
        printf(" * ");
      else if (histogram[j] < height && histogram[j] > 0)
        printf("   ");
      else if (histogram[j] == -1)
        break;
    }
    printf("\n");
  }

  // Create the column ledger
  // Calculate spacer width
  printf("   ");
  for (i = 0; i < MAXWORDS; ++i) {
    if (histogram[i] == -1) {
      printf("--");
      break;
    } else if (i + 1 < MAXWORDS) {
      if (histogram[i + 1] == -1) {
        printf("--");
        break;
      }
    }
    if (histogram[i] > 0) printf("---");
  }
  // Calculate word number and padding
  printf("\n   ");
  for (i = 0; i < MAXWORDS; ++i) {
    if (histogram[i] == -1) break;
    if (histogram[i] > 0) {
      if (i + 1 <= 9)
        printf(" %d ", i + 1);
      else
        printf("%d ", i + 1);
    }
  }
  printf("\n");
}
