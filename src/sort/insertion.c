
#include "sort.h"

void insertion(int *array, int size, int (*comp)(int, int))
{
  for (int i = 1; i < size; ++i)
  {
    int j = i;

    while (j > 0 && comp(array[j - 1], array[j]) > 0)
    {
      swap(array + j - 1, array + j);
      --j;
    }
  }
}