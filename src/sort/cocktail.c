
#include "sort.h"

static int __left_to_right(int *array, int size, int (*cmp)(int, int))
{
  int done = 1;

  for (int i = 0; i < size - 1; ++i)
  {
    if (cmp(array[i], array[i + 1]) > 0)
    {
      swap(array + i, array + i + 1);
      done = 0;
    }
  }

  return done;
}

static int __right_to_left(int *array, int size, int (*cmp)(int, int))
{
  int done = 1;

  for (int i = size - 2; i > 0; --i)
  {
    if (cmp(array[i], array[i - 1]) < 0)
    {
      swap(array + i, array + i - 1);
      done = 0;
    }
  }

  return done;
}

void cocktail(int *array, int size, int (*cmp)(int, int))
{
  int i = 0;

  while (42)
  {
    if (__left_to_right(array + i, size - i * 2, cmp))
      break;

    if (__right_to_left(array + i, size - i * 2, cmp))
      break;

    ++i;
  }
}