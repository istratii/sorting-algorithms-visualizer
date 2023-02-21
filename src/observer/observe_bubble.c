
#include "observer.h"

static void __observe_bubble(int *array, int size, int (*cmp)(int, int), struct queue *queue)
{
  int i = 0;

  struct state *curr = NULL;
  struct state *temp = NULL;

  state_init(&curr);

  if (curr == NULL)
    return;

  while (i + 1 < size)
  {
    ++(curr->comparisons);

    curr->swap_src = -1;
    curr->swap_dst = -1;

    if (cmp(array[i], array[i + 1]) > 0)
    {
      swap(array + i, array + i + 1);
      curr->swap_src = i;
      curr->swap_dst = i + 1;
      ++(curr->swaps);

      i = i - 1 - (i > 0);
    }

    (curr->accesses) += 2;
    ++(curr->comparisons);
    ++i;

    state_init_from(&temp, curr);
    queue_push(queue, temp);
  }

  state_free(&curr);
}

struct queue *observe_bubble(int *array, int size, int (*cmp)(int, int))
{
  struct queue *queue = NULL;

  queue_init(&queue);

  if (queue != NULL)
    __observe_bubble(array, size, cmp, queue);

  return queue;
}