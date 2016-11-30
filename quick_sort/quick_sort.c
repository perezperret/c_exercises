#include <stdio.h>

void quick_sort(int v[], int left, int right);
void swap(int v[], int i, int j);

/* quicksort alg: sort v[left]...v[right] into asc order */

int main()
{
  int o[] = { 3, 5, 12, 1, 4, 6 };
  int n = 5;

  for (int i = 0; i < 5; i ++) {
    printf("%d", o[i]);
  }
  putchar('\n');


  quick_sort(o, 0, 5);

  for (int i = 0; i < 6; i ++) {
    printf("%d", o[i]);
  }
  putchar('\n');
}

void quick_sort(int v[], int left, int right)
{
  int i, last;

  if (left >= right) /* do nothing if array contains fewer than two elements */
    return;
  swap(v, left, (left + right) / 2); /* move partition elem to v[0] */
  last = left;

  for (i = left + 1; i <= right; i++) /* partition */
    if (v[i] < v[left])
      swap(v, ++last, i);
  swap(v, left, last);

  quick_sort(v, left, last - 1); /* restore partition element */
  quick_sort(v, last + 1, right);
}


void swap(int v[], int i, int j)
{
  int t;
  t = v[i];
  v[i] = v[j];
  v[j] = t;
}
