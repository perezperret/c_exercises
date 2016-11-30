#include <stdio.h>
#include <string.h>

void reverse(char string[], int start, int end);
void swap(char string[], int i, int j);

/* quicksort alg: sort v[hi]...v[lo] into asc order */

int main()
{
  char input[] = "reverse me";
  int start = 0;
  int end = strlen(input) - 1;

  printf("prereverse: %s\n", input);

  reverse(input, start, end);

  printf("postreverse: %s\n", input);
}

void reverse(char s[], int i, int j)
{
  if (i < j) {
    swap(s, i, j);
    reverse(s, i + 1, j - 1);
  }
}

void swap(char v[], int i, int j)
{
  char temp = v[i];
  v[i] = v[j];
  v[j] = temp;
}
