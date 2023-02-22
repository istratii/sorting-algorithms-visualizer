
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "observer/observer.h"
#include "sort/sort.h"
#include "visualizer/visualizer.h"

int comp(int a, int b)
{
  return a - b;
}

int main(void)
{
  srand(time(NULL));
  const int SIZE = 1000;
  int array[SIZE];
  for (int i = 0; i < SIZE; ++i)
    array[i] = rand() % 40000 - 5000;
  int cpy[SIZE];
  memcpy(cpy, array, SIZE * sizeof(int));
  struct setup setup = { array, SIZE, comp };
  struct queue *q = OBSERVE_QUICK(&setup);
  visualize(cpy, SIZE, q);
  queue_free(&q, free);

  return 0;
}
