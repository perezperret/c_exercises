#include "stdio.h"

/* Print fahrenheit - celsius table for fahr = [0...300] */

int main()
{
  float fahr, celsius;
  int lower, upper, step;

  lower = 0; /* lower limit of table */
  upper = 300; /* upper limit */
  step = 20;

  fahr = lower;

  printf("\nFahrenheit to Celcius table\n\n");

  while (fahr <= upper)
  {
    celsius = (5.0 / 9.0) * (fahr - 32.0);
    printf("%3.0f\t%6.1f\n", fahr, celsius);
    fahr = fahr + step;
  }

  printf("\n");
}
