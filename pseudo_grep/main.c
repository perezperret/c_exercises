#include <stdio.h>

#define MAXLINE 1000

int get_line(char vector[], int max_line);
int strindex(char substr[], char supstr[]);

int main()
{
  char substr[] = "ould";
  char supstr[MAXLINE];
  int found = 0;

  while (get_line(supstr, MAXLINE))
    if (strindex(substr, supstr) >= 0) {
      printf("%s\n", supstr);
      ++ found;
    }
  return found;
}
