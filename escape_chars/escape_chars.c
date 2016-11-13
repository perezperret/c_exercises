#include <stdio.h>

void escape_chars(char target[], char source[]);

int main()
{
  char * source = "An escaped\t\tweird little\n\tstring";
  char target[100];

  escape_chars(target, source);
  printf("source: %s\n", source);
  printf("target: %s\n", target);

  return 0;
}

void escape_chars(char target[], char source[])
{
  int i = 0; // Index to write to in target
  int j = 0; // Index to read from in source

  while (source[j] != '\0') {
    switch (source[j]) {
    case '\n':
      target[i] = '\\';
      target[++i] = 'n';
      break;
    case '\t':
      target[i] = '\\';
      target[++i] = 't';
      break;
    default:
      target[i] = source[j];
      break;
    }

    ++i;
    ++j;
  }

  target[i] = '\0';
}
