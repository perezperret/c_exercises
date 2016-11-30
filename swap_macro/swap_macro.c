#include <stdio.h>

/* K&R 4 - 14: Define a macro swap(t, x, y) that swaps x and y of type t */

#define swap(t, x, y) do { t temp = x; x = y; y = temp; } while (0)

int main()
{
  // swap ints
  int x = 1, y = 2;
  printf("x=%d. y=%d\n", x, y);
  swap(int, x, y);
  printf("x=%d. y=%d\n", x, y);

  // swap chars
  char a = 'a', b = 'b';
  printf("a=%c. b=%c\n", a, b);
  swap(char, a, b);
  printf("a=%c. b=%c\n", a, b);
}
