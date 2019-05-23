#include <stdio.h>

// Exercise 1-5. Modify the temperature conversion program to print the table in reverse order, that is, from 300 degrees to 0.

int main()
{
  float fahr, celsius;
  int lower, upper, step;

  lower = 0;
  upper = 300;
  step = 20;

  printf("---------------------------\n");
  printf("|    Celsius | Fahrenheit |\n");
  printf("|------------+------------|\n");
  for (celsius = upper; celsius >= lower; celsius = celsius - step)
  {
    fahr = ((9.0 / 5.0) * celsius) + 32.0;
    printf("| %10.1f | %10.1f |\n", celsius, fahr);
  }
  printf("---------------------------\n");
}
