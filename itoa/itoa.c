#include <stdio.h>
#define MAXLEN 100

/* Two implementations of simple int to char array conversion */

void itoa_loop(int input, char output[], int length);
void itoa_recursive(int input);
void reverse(char input[], int length);

int main()
{
  char output[MAXLEN];
  int input = 12345;
  int i = 0;

  itoa_loop(input, output, MAXLEN);
  printf("%s\n", output);

  itoa_recursive(input);
  putchar('\n');
}

void itoa_recursive(int c)
{
  if (c < 0) {
    putchar('-');
    c = -c;
  }

  if (c / 10) {
    itoa_recursive(c / 10);
  }
  putchar((c % 10) + '0');
}

void itoa_loop(int c, char o[], int n)
{
  int i = 0;
  while (c > 0 && i < n) {
    o[i] = (c % 10) + '0';
    c /= 10;
    i ++;
  }
  o[i] = '\0';
  reverse(o, i);
}

void reverse(char o[], int n)
{
  int i = 0;
  int j = n - 1;
  int t;
  while (i < j) {
    t = o[i];
    o[i] = o[j];
    o[j] = t;
    i++;
    j--;
  }
}
