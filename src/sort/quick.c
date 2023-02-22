
#include "sort.h"

static void __quick(int *array, int size, int (*cmp)(int, int))
{
  if (size <= 1)
    return;

  int pivot = array[size >> 1];
  int i = -1;
  int j = size;

  while (42)
  {
    while (cmp(array[++i], pivot) < 0)
      ;
    while (cmp(array[--j], pivot) > 0)
      ;

    if (i >= j)
      break;

    swap(array + i, array + j);
  }

  __quick(array, i, cmp);
  __quick(array + i, size - i, cmp);
}

void quick(int *array, int size, int (*cmp)(int, int))
{
  __quick(array, size, cmp);
}
