#include <ctype.h>
#include <stdio.h>

double atof(char source_str[]);

int main()
{
  char source_str[] = "-123.456";
  printf("string: %s. Float: %.3f\n", source_str, atof(source_str));
}

double atof(char s[])
{
  double val, power;
  int i, sign;

  // skip initial whitespace
  for (i = 0; isspace(s[i]); i ++)
    ;

  // record sign if given
  sign = (s[i] == '-') ? -1 : 1;
  if (s[i] == '-' || s[i] == '+')
    i ++;

  // record integer values
  for (val = 0.0; isdigit(s[i]); i ++)
    val = 10.0 * val + (s[i] - '0');
  if (s[i] == '.')
    i ++;

  // record rational values and augment division power
  for (power = 1.0; isdigit(s[i]); i++) {
    val = 10.0 * val + (s[i] - '0');
    power *= 10;
  }
  return sign * val / power;
}
