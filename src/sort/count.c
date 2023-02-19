
#include "sort.h"

#define LIMIT 1000

void count(int *array, int size, int (*comp)(int, int))
{
  int M[LIMIT] = { 0 };

  for (int i = 0; i < size; ++i)
    ++M[array[i]];

  int k = 0;

  for (int i = 0; i < LIMIT; ++i)
  {
    if (M[i] <= 0)
      continue;

    for (int j = 0; j < M[i]; ++j)
      array[k++] = i;
  }
}