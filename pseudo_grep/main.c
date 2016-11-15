#include <stdio.h>

#define MAXLINE 1000

/**
 * Example from chapter 4 K&R
 * V1 self made
 * V2 improved with book
 * Specific case of UNIX `grep` (only substrings)
 */

int get_line(char vector[], int max_line);
int strindex(char source[], char pattern[]);

int main()
{
  char source[MAXLINE];
  char pattern[] = "ould";
  int found = 0;

  // Iterate through lines
  while (get_line(source, MAXLINE))
    // If pattern is found, print it
    if (strindex(source, pattern) >= 0) {
      printf("%s", source);
      ++ found;
    }
  return found;
}
