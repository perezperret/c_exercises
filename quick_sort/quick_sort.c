#include <stdio.h>

void quick_sort(int v[], int hi, int lo);
int partition(int v[], int hi, int lo);
void swap(int v[], int i, int j);
void print_arr(int v[], int n);

/* quicksort alg: sort v[hi]...v[lo] into asc order */

int main()
{
  int o[] = { 3, 5, 12, 1, 4, 6 };
  int n = 6;

  printf("presort\n");
  print_arr(o, n);
  putchar('\n');

  quick_sort(o, 0, n - 1);

  printf("postsort\n");
  print_arr(o, n);
  putchar('\n');
}

void quick_sort(int v[], int lo, int hi)
{
  int p;
  if (lo < hi) {
    p = partition(v, lo, hi);
    quick_sort(v, lo, p - 1);
    quick_sort(v, p + 1, hi);
  }
}

void print_arr(int a[], int n)
{
  for (int i = 0; i < n; i ++) {
    printf("%d\t", a[i]);
  }
  putchar('\n');
}

int partition(int v[], int lo, int hi)
{
  int pivot = v[hi];
  int i = lo, j = lo;

  for (; j <= hi - 1; j ++) {
    if (v[j] <= pivot) {
      swap(v, i, j);
      i ++;
    }
  }

  swap(v, i, hi);
  return i;
}

void swap(int v[], int i, int j)
{
  int t;
  t = v[i];
  v[i] = v[j];
  v[j] = t;
}
