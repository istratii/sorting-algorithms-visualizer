
#include "observer.h"

void __observe_insertion(struct setup *setup, struct queue *states)
{
  struct state *curr = NULL;
  struct state *temp = NULL;

  state_init(&curr);

  // last i < setup->size
  ++(curr->comparisons);

  for (int i = 1; i < setup->size; ++i)
  {
    // i < setup->size
    ++(curr->comparisons);
    RESET_SWAP_INDEXES(curr);

    int j = i;

    while (j > 0 && setup->cmp(setup->array[j - 1], setup->array[j]) > 0)
    {
      curr->accesses += 2;
      curr->comparisons += 2;
      curr->swap_src = j - 1;
      curr->swap_dst = j;
      curr->swaps = curr->swaps + 1;
      swap(setup->array + j - 1, setup->array + j);
      --j;

      SAVE_STATE(states, curr, temp);
    }

    // count loop end
    if (j <= 0)
    {
      ++(curr->comparisons);
    }
    else
    {
      curr->accesses += 2;
      curr->comparisons += 2;
    }

    RESET_SWAP_INDEXES(curr);
    SAVE_STATE(states, curr, temp);
  }
}