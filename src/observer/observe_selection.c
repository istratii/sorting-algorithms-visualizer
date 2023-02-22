
#include "observer.h"

void __observe_selection(struct setup *setup, struct queue *states)
{
  struct state *curr = NULL;
  struct state *temp = NULL;

  state_init(&curr);

  // loop end
  ++(curr->comparisons);

  for (int i = 0; i + 1 < setup->size; ++i)
  {
    ++(curr->comparisons);
    RESET_SWAP_INDEXES(curr);

    int j = i;
    int k = i + 1;

    // loop end
    ++(curr->comparisons);

    for (; k < setup->size; ++k)
    {
      curr->comparisons += 2;
      curr->accesses += 2;

      if (setup->cmp(setup->array[k], setup->array[j]) < 0)
        j = k;
    }

    ++(curr->comparisons);

    if (j != i)
    {
      ++(curr->swaps);
      curr->swap_src = j;
      curr->swap_dst = i;

      swap(setup->array + j, setup->array + i);
    }

    SAVE_STATE(states, curr, temp);
  }
}