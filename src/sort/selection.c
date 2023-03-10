
#include "sort.h"

void selection(int *array, int size, int (*cmp)(int, int))
{
  for (int i = 0; i + 1 < size; ++i)
  {
    int j = i;
    int k = i + 1;

    for (; k < size; ++k)
      if (cmp(array[k], array[j]) < 0)
        j = k;

    if (j != i)
      swap(array + j, array + i);
  }
}