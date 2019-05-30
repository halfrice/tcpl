#include <stdio.h>

// How would you test the word count program? What kinds of innput are most
// likely to uncover bugs if there are any?

#define IN 1
#define OUT 0

int main() {
  int c, nl, nw, nc, state;

  state = OUT;
  nl = nw = nc = 0;
  while ((c = getchar()) != EOF) {
    ++nc;
    if (c == '\n') ++nl;

    // Old shitty way
    // if (c == ' ' || c == '\n' || c == '\t')

    // Spicy new way
    // 97-122 lowercase letters
    // 65-90 uppercase
    // 48-57 numbers
    // 45 dash ... and so on
    if ((c >= 97 && c <= 122) || (c >= 65 && c <= 90) || (c >= 48 && c <= 57) ||
        c == 45)
      state = OUT;
    else if (state == OUT) {
      state = IN;
      ++nw;
    }
  }
  printf("lines: %d\n words: %d\n chars: %d\n", nl, nw, nc);
}
