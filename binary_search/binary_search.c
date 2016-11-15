#include <time.h>
#include <stdlib.h>
#include <stdio.h>

/* Binary search excercises from C Prog Lang */
/* TODO: benchmark is being performed on unsorted array */

int binsearch_a(int x, int v[], int n);
int binsearch_b(int x, int v[], int n);
void get_test_data(int len, int v[]);

int main() {

  // TODO: move to function
  srand(time(NULL));
  int len = 1000000;
  int v[len];
  get_test_data(len, v);
  int x = rand();

  clock_t begin_a = clock();
  binsearch_a(x, v, len);
  clock_t end_a = clock();

  clock_t begin_b = clock();
  binsearch_b(x, v, len);
  clock_t end_b = clock();

  double time_a = (double)(end_a - begin_a) / CLOCKS_PER_SEC;
  double time_b = (double)(end_b - begin_b) / CLOCKS_PER_SEC;

  printf("bs_a: %f s.\n", time_a);
  printf("bs_a: %f s.\n", time_b);
}

/* binsearch: find x in sorted array */
int binsearch_a(int x, int v[], int n)
{
  int low, high, mid;

  low = 0;
  high = n - 1;
  while (low <= high) {
    mid = (low + high) / 2;
    if (x < v[mid])
      high = mid - 1;
    else if (x > v[mid])
      low = mid + 1;
    else
      return mid;
  }
  return -1;
}

/* binsearch: find x in sorted array */
int binsearch_b(int x, int v[], int n)
{
  int low, high, mid;

  low = 0;
  high = n - 1;
  while (low <= high) {
    mid = (low + high) / 2;
    if (x < v[mid])
      high = mid - 1;
    else
      low = mid + 1;
  }
  return (x == v[low]) ? low : -1;
}

void get_test_data(int len, int v[]) {

  while (len > 0) {
    len --;
    v[len] = rand();
  }
}
