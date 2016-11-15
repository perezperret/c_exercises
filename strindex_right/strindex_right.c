#include <stdio.h>

int strindex_right(char source[], char pattern[]);
int str_len(char s[]);

int main()
{
  // TODO: proper tests
  char len_test[] = "123456789";
  int len = str_len(len_test);
  printf("len_test_len: %d == 9 ?\n", len);

  char pattern[] = "two";
  char index_test1[] = "zero one two three four five six seven eight nine "
                       "nine eight seven six five four three two one zero";
  char index_test2[] = "zero one two three four five six seven eight nine "
                       "nine eight seven six five four three ";
  // Calculate strindex_right
  int index1 = strindex_right(index_test1, pattern);
  // Calculate expected strindex_right
  int index2 = str_len(index_test2);
  printf("index_test_index: %d == %d ?\n", index1, index2);

  return 0;
}

int strindex_right(char s[], char p[])
{
  int i, j, k;
  int len_s = str_len(s);
  int len_p = str_len(p);

  // Iterate source
  for (i = len_s; i != 0; i--) {
    for (j = i, k = len_p; s[j] == p[k-1] && j != 0 && k != 0; k--, j--)
      ;
    if (k == 0)
      return i - (len_p - 1);
  }
  return -1;
}

int str_len(char s[])
{
  int i;
  for(i = 0; s[i] != '\0'; i ++)
    ;
  return i;
}
