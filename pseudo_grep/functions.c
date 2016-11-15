#include <stdio.h>
#include <stdbool.h>

#define MAXLINE 1000

int get_line(char vector[], int max_line);
int strindex(char substr[], char supstr[]);

// TODO: use test framework
int test_get_line()
{
  char vector[MAXLINE];
  while (get_line(vector, MAXLINE)) {
    printf("%s-", vector);
  }
  printf("\n");
  return 0;
}

int test_strindex()
{
  char * supstr = "I once had very good friend with only one eye in his face"; // length = 56
  char * substr = "one"; // index = 38
  printf("%d\n", strindex(substr, supstr));
  return 0;
}

int get_line(char vector[], int max_line)
{
  int i, c;
  i = 0;
  // Copy chars until newline or end of file
  while ((c = getchar()) != '\n' && c != EOF && i < max_line)
    vector[i++] = c;
  // Count closing empty line
  if (c == '\n')
    vector[i++] = c;
  // Close string
  vector[i] = '\0';
  // Return string length
  return i;
}

int strindex(char substr[], char supstr[])
{
  int i, j;
  i = j = 0;
  bool found = 0;
  while (supstr[i] != '\0') {
    if (supstr[i] == substr[0]) {
      found = 1;
      j = 0;
      while (substr[j] != '\0') {
        if (substr[j] != supstr[i + j]) {
          found = 0;
          break;
        }
        ++ j;
      }
      if (found)
        return i;
    }
    i ++;
  }
  return -1;
}
