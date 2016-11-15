#include <stdio.h>

#define MAXLINE 1000

int get_line(char vector[], int max_line);
int strindex(char source[], char pattern[]);

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
  // Include newline
  if (c == '\n')
    vector[i++] = c;
  // Close string
  vector[i] = '\0';
  // Return string length
  return i;
}

int strindex(char s[], char p[])
{
  int i, j, k;
  // Iterate source
  for (i = 0; s[i] != '\0'; i++) {
    // Iterate pattern while it matches
    for (j = i, k = 0; p[k] != '\0' && s[j] == p[k]; j++, k++)
      ;
    // If first pattern char was found and pattern was iterated
    // return index of first char
    if (k > 0 && p[k] == '\0')
      return i;
  }
  // If nothing is found return `-1`
  return -1;
}
