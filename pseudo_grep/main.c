#include <stdio.h>

#define MAXLINE 1000

int get_line(char vector[], int max_line);
int strindex(char source[], char pattern[]);

int main()
{
  char source[MAXLINE];
  char pattern[] = "ould";
  int found = 0;

  while (get_line(source, MAXLINE))
    if (strindex(source, pattern) >= 0) {
      printf("%s", source);
      ++ found;
    }
  return found;
}
