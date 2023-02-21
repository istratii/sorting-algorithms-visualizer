
#include <stdio.h>
#include <stdlib.h>

#include "observer/observer.h"
#include "sort/sort.h"
#include "visualizer/visualizer.h"

int comp(int a, int b)
{
  return a - b;
}

int main(void)
{
  int array[100];
  for (int i = 0; i < 100; ++i)
    array[i] = rand() % 1000 - 500;
  int cpy[100];
  memcpy(cpy, array, 100 * sizeof(int));
  struct queue *q = observe_bubble(array, 100, comp);
  visualize(cpy, 100, q);
  queue_free(&q, free);

  return 0;
}
