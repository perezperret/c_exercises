#include <stdio.h>

#define IN 1 /* inside a word */
#define OUT 0 /* outside a word */

/* ex. 1-13 word length histogram */

int main()
{
  int i, j, c, wl, state;
  int length_data[25];

  state = OUT;
  wl = 0;

  for (i = 0; i < 25; ++i)
    length_data[i] = 0;

  while ((c = getchar()) != EOF) {
    // upon exiting a word register its length
    if (c == ' ' || c == '\n' || c == '\t') {
      if (wl < 25)
        ++length_data[wl];
      else
        ++length_data[24];
      state = OUT;
    // upon entering a word set state and start count
    } else if (state == OUT) {
      state = IN;
      wl = 1;
    // while character is in word increase length count
    } else {
      ++wl;
    }
  }

  printf("\nWord length histogram\n");
  for (i = 1; i < 25; ++i) {
    printf("%3d: ", i);
    for (j = 0; j < length_data[i]; ++j)
      printf("-");
    printf("\n");
  }
}
