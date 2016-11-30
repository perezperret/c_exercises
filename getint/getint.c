#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

/* K&R C copied pointers example */

int getint(int *pn);

int main()
{
  int *pn;
  int res;
  while ((res = getint(pn)) != EOF)
    printf("%d\n", *pn);
}

int getint(int *pn)
{
  int c, sign;

  while (isspace(c = getc(stdin))) // skip whitespace
    ;

  if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
    ungetc(c, stdin);
    return 0;
  }

  sign = (c == '-') ? -1 : 1;

  if (c == '+' || c == '-')
    c = getc(stdin);

  for (*pn = 0; isdigit(c); c = getc(stdin))
    *pn = 10 * *pn + (c - '0');

  *pn *= sign;

  if (c != EOF)
    ungetc(c, stdin);

  return c;
}
