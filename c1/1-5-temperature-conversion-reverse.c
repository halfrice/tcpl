#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

// Exercise 1-5. Modify the temperature conversion program to print the table in reverse order, that is, from 300 degrees to 0.

int main()
{
  float fahr, celsius;

  printf("------------------------\n");
  printf("| Fahrenheit | Celsius |\n");
  printf("|------------+---------|\n");
  for (fahr = UPPER; fahr >= LOWER; fahr = fahr - STEP)
  {
    celsius = (5.0 / 9.0) * (fahr - 32.0);
    printf("| %10.1f | %7.1f |\n", fahr, celsius);
  }
  printf("------------------------\n");
}