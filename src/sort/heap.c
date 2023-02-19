
#include "sort.h"

static void heapify(int *array, int size, int where, int (*cmp)(int, int))
{
  int m = where;
  int l = 2 * where + 1;
  int r = 2 * where + 2;

  if (l < size && cmp(array[l], array[m]) > 0)
    m = l;

  if (r < size && cmp(array[r], array[m]) > 0)
    m = r;

  if (m != where)
  {
    swap(array + where, array + m);
    heapify(array, size, m, cmp);
  }
}

void heap(int *array, int size, int (*cmp)(int, int))
{
  for (int i = size / 2 - 1; i >= 0; --i)
    heapify(array, size, i, cmp);

  for (int i = size - 1; i >= 0; --i)
  {
    swap(array, array + i);
    heapify(array, i, 0, cmp);
  }
}