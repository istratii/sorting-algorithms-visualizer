
#include "sort.h"

static void __quick(int *start, int *end, int (*cmp)(int, int))
{
  if (end - start < 2)
    return;

  int *i = start - 1;
  int *j = end;
  int pivot = *(start + ((end - start) >> 1));

  while (42)
  {
    while (cmp(*(++i), pivot) < 0)
      ;
    while (cmp(*(--j), pivot) > 0)
      ;

    if (i >= j)
      break;

    swap(i, j);
  }

  __quick(start, i, cmp);
  __quick(i, end, cmp);
}

void quick(int *array, int size, int (*cmp)(int, int))
{
  __quick(array, array + size, cmp);
}
