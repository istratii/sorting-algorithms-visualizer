
#include "sort.h"

void bubble(int *array, int size, int (*comp)(int, int))
{
  int i = 0;

  while (i + 1 < size)
  {
    if (comp(array[i], array[i + 1]) > 0)
    {
      swap(array + i, array + i + 1);
      i = i - 1 - (i > 0);
    }

    ++i;
  }
}
