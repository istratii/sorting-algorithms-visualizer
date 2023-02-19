
#include "sort.h"

static int __left_to_right(int *start, int *end, int (*cmp)(int, int))
{
  int done = 1;

  for (; start < end; ++start)
  {
    if (cmp(*start, *(start + 1)) > 0)
    {
      swap(start, start + 1);
      done = 0;
    }
  }

  return done;
}

static int __right_to_left(int *start, int *end, int (*cmp)(int, int))
{
  int done = 1;

  for (; end >= start; --end)
  {
    if (cmp(*end, *(end + 1)) > 0)
    {
      swap(end, end + 1);
      done = 0;
    }
  }

  return done;
}

void cocktail(int *array, int size, int (*cmp)(int, int))
{
  int *start = array;
  int *end = array + size - 1;

  while (42)
  {
    if (__left_to_right(start, end, cmp))
      break;

    --end;

    if (__right_to_left(start, end - 1, cmp))
      break;

    ++start;
  }
}