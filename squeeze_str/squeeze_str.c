#include <stdio.h>

char * squeeze(char string[], char character);

int main()
{
  // TODO test squeeze
  // char s[] = "abcdabcd";
  // printf("%s\n", squeeze(s, 'a'));
}

char * squeeze(char s[], char c)
{
  int i, j;

  for (i = j = 0; s[i] != '\0'; i++) {
    if (s[i] != c) {
      s[j++] = s[i];
    }
  }
  s[j]='\0';

  return s;
}
