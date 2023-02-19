
#include <stdio.h>

#include "sort.h"

static void __merge(int *s1, int *e1, int *s2, int *e2, int (*cmp)(int, int))
{
  if (s2 == e2)
    return;

  int size = e2 - s1;
  int *start = s1;
  int *out = malloc(size * sizeof(int));
  int *tmp = out;

  while (s1 < e1 && s2 < e2)
  {
    if (cmp(*s1, *s2) < 0)
      *tmp = *(s1++);

    else
      *tmp = *(s2++);

    ++tmp;
  }

  while (s1 < e1)
    *(tmp++) = *(s1++);

  while (s2 < e2)
    *(tmp++) = *(s2++);

  memcpy(start, out, size * sizeof(int));
  free(out);
}

static void __merge_sort(int *start, int *end, int (*cmp)(int, int))
{
  if (end - start <= 1)
    return;

  int *mid = start + ((end - start) >> 1);
  __merge_sort(start, mid, cmp);
  __merge_sort(mid, end, cmp);
  __merge(start, mid, mid, end, cmp);
}

void merge(int *array, int size, int (*cmp)(int, int))
{
  __merge_sort(array, array + size, cmp);
}