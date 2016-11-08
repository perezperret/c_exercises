#include <stdio.h>
#include <stdbool.h>

bool checkbalance();
int indexof(char value, char array[], int length);

int main() {

  char openers[3] = { '{','(','[' };
  char closers[3] = { '}',')',']' };
  int length = 3;

  /* TODO: indexof tests */
  // printf("%d\n", indexof('{', openers, 3));
  // printf("%d\n", indexof(')', closers, 3));
  // printf("%d\n", indexof(']', closers, 3));
  // printf("%d\n", indexof('{', closers, 3));

  printf("%s\n", checkbalance(openers, closers, length) ? "true" : "false");
}

bool checkbalance(char openers[], char closers[], int length) {

  int stackpointer = 0;
  char stack[1000];

  int curr_char;
  int curr_symbol;

  int iter = 0;

  while ((curr_char = getchar()) != EOF) {
    if ((curr_symbol = indexof(curr_char, openers, length)) >= 0) {
      stackpointer++;
      stack[stackpointer] = curr_symbol;
    } else if ((curr_symbol = indexof(curr_char, closers, length)) >= 0) {
      if (curr_symbol == stack[stackpointer]) {
        --stackpointer;
      } else {
        return false;
      }
    }
    iter++;
  }

  return stackpointer == 0;
}

int indexof(char value, char array[], int length) {
  for (int i = 0; i < length; ++i) {
    if (array[i] == value) {
      return i;
    }
  }

  return -1;
}
