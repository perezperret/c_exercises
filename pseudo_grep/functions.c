#include <stdio.h>

#define MAXLINE 1000

int get_line(char vector[], int max_line);

int main()
{
  char vector[MAXLINE];
  while (get_line(vector, MAXLINE)) {
    printf("%s-", vector);
  }
  printf("\n");
  return 0;
}

int get_line(char vector[], int max_line)
{
  int i, c;
  i = 0;
  // Get chars until newline
  while ((c = getchar()) != '\n' && i < max_line) {
    // Break on end of file
    if (c == EOF) {
      return 0;
    }
    vector[i] = c;
    ++ i;
  }
  vector[i] = '\0';
  return i;
}

int strindex(char string[], int n) {
  return 0;
}
