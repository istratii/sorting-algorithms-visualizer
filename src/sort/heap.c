
#include "sort.h"

static void heapify(int *array, int size, int where, int (*comp)(int, int))
{
  int m = where;
  int l = 2 * where + 1;
  int r = 2 * where + 2;

  if (l < size && comp(array[l], array[m]) > 0)
    m = l;

  if (r < size && comp(array[r], array[m]) > 0)
    m = r;

  if (m != where)
  {
    swap(array + where, array + m);
    heapify(array, size, m, comp);
  }
}

void heap(int *array, int size, int (*comp)(int, int))
{
  for (int i = size / 2 - 1; i >= 0; --i)
    heapify(array, size, i, comp);

  for (int i = size - 1; i >= 0; --i)
  {
    swap(array, array + i);
    heapify(array, i, 0, comp);
  }
}