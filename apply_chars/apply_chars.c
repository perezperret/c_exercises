#include <stdio.h>

/**
 * Ex 3-2b: Change visible string representation of tab and newline to correct chars
 */

void apply_chars(char target[], char source[]);

int main()
{
  char * source = "An escaped\\t\\tweird little\\n\\tstring";
  char target[100];

  apply_chars(target, source);
  printf("source: %s\n", source);
  printf("target: %s\n", target);

  return 0;
}

void apply_chars(char target[], char source[])
{
  int i = 0; // Index to write to in target
  int j = 0; // Index to read from in source

  while (source[j] != '\0') {

    if (source[j] == '\\') {
      switch (source[++j]) {
      case 'n':
        target[i] = '\n';
        break;
      case 't':
        target[i] = '\t';
        break;
      default:
        target[i] = source[--j];
        break;
      }
    } else {
      target[i] = source[j];
    }

    ++i;
    ++j;
  }

  target[i] = '\0';
}
