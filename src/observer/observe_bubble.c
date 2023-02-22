
#include "observer.h"

void __observe_bubble(struct setup *setup, struct queue *states)
{
  int i = 0;

  struct state *curr = NULL;
  struct state *temp = NULL;

  state_init(&curr);

  // loop end
  ++(curr->comparisons);

  while (i + 1 < setup->size)
  {
    curr->comparisons += 2;
    curr->accesses += 2;
    RESET_SWAP_INDEXES(curr);

    if (setup->cmp(setup->array[i], setup->array[i + 1]) > 0)
    {
      swap(setup->array + i, setup->array + i + 1);
      curr->swap_src = i;
      curr->swap_dst = i + 1;
      ++(curr->swaps);

      i = i - 1 - (i > 0);
    }

    SAVE_STATE(states, curr, temp);
    ++i;
  }

  state_free(&curr);
}