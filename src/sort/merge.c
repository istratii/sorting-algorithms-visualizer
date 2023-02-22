
#include <stdio.h>

#include "sort.h"

static void __merge(int *array, int size, int (*cmp)(int, int))
{
  if (size == 0)
    return;

  int *out = malloc(size * sizeof(int));
  int *tmp = out;
  int i = 0;
  int j = size >> 1;

  while (i < (size >> 1) && j < size)
  {
    if (cmp(array[i], array[j]) < 0)
      *(tmp++) = array[i++];

    else
      *(tmp++) = array[j++];
  }

  while (i < (size >> 1))
    *(tmp++) = array[i++];

  while (j < size)
    *(tmp++) = array[j++];

  memcpy(array, out, size * sizeof(int));
  free(out);
}

void merge(int *array, int size, int (*cmp)(int, int))
{
  if (size <= 1)
    return;

  merge(array, size >> 1, cmp);
  merge(array + (size >> 1), size - (size >> 1), cmp);
  __merge(array, size, cmp);
}