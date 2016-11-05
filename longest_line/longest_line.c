#include <stdio.h>

#define MAXLINE 1000 /* max input line size */

int newgetline(char line[], int maxline);
void copy(char to[], char from[]);

/* Print longest input line */

int main()
{
  int len; /* Current line length */
  int max; /* Current max length */

  char line[MAXLINE]; /* Current line */
  char longest[MAXLINE]; /* Current longest line */

  max = 0;

  while ((len = newgetline(line, MAXLINE)) > 0) {
    if (len > max) {
      max = len;
      copy(longest, line);
    }
  }

  if (max > 0) /* If at least a line was found */
    printf("%s", longest);

  return 0;
}

/*
 * newgetline: read a line into s, return length
 */
int newgetline(char line[], int maxline)
{
  int c, i;

  for (i = 0; i < maxline - 1
        && ((c = getchar()) != EOF && c != '\n'); ++i)
    line[i] = c;

  if (c == '\n') {
    line[i] = c;
    ++i;
  }
  line[i] = '\0';
  return i;
}

/*
 * copy 'from' into 'to'; assumes 'to' is big enough
 */
void copy(char to[], char from[])
{
  int i = 0;
  while ((to[i] = from[i]) != '\0')
    ++i;
}
