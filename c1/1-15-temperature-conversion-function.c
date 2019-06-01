#include <stdio.h>

// Exercise 1-15. Rewrite the temperature conversion program of Section 1.2 to
// use a function for conversion.

float convertToCelsius(float n);
float convertToFahrenheit(float n);

int main() {
  float fahr, celsius;
  int lower, upper, step;

  lower = 0;
  upper = 300;
  step = 20;

  fahr = lower;
  while (fahr <= upper) {
    printf("%3.0f^F %6.1f^C\n", fahr, convertToCelsius(fahr));
    fahr = fahr + step;
  }
}

float convertToCelsius(float n) { return (5.0 / 9.0) * (n - 32.0); }

float convertToFahrenheit(float n) { return ((9.0 / 5.0) * n) + 32.0; }