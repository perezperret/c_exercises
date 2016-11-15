#include <time.h>
#include <stdlib.h>
#include <stdio.h>

/* Shell sort implementation from C Prog lang */

void shell_sort(int vector[], int length);
void get_test_data(int len, int v[]);

int main()
{
  // TODO: move to function
  srand(time(NULL));
  int len = 1000000;
  int v[len];
  get_test_data(len, v);

  shell_sort(v, len);

  while (len > 0) {
    len --;
    printf("%d\n", v[len]);
  }

  return 0;
}

void shell_sort(int v[], int n)
{
  int gap, i, j, temp;

  for (gap = n/2; gap > 0; gap /= 2) {
    for (i = gap; i < n; i ++) {
      for (j = i - gap; j >= 0 && v[j] > v[j + gap]; j -= gap) {
        temp = v[j];
        v[j] = v[j + gap];
        v[j + gap] = temp;
      }
    }
  }
}

void get_test_data(int len, int v[]) {

  while (len > 0) {
    len --;
    v[len] = rand();
  }
}
