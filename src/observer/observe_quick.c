
#include "observer.h"

static void __quick(struct setup *setup, struct queue *states, struct state *curr, const int *begin)
{
  struct state *temp = NULL;

  RESET_SWAP_INDEXES(curr);
  ++(curr->comparisons);

  if (setup->size <= 1)
  {
    SAVE_STATE(states, curr, temp);
    return;
  }

  ++(curr->accesses);

  int pivot = setup->array[setup->size >> 1];
  int i = -1;
  int j = setup->size;

  while (42)
  {
    RESET_SWAP_INDEXES(curr);
    curr->comparisons += 2;
    curr->accesses += 2;

    while (setup->cmp(setup->array[++i], pivot) < 0)
    {
      ++(curr->comparisons);
      ++(curr->accesses);
    }

    while (setup->cmp(setup->array[--j], pivot) > 0)
    {
      ++(curr->comparisons);
      ++(curr->accesses);
    }

    ++(curr->comparisons);

    if (i >= j)
    {
      SAVE_STATE(states, curr, temp);
      break;
    }

    ++(curr->swaps);
    curr->swap_src = setup->array + i - begin;
    curr->swap_dst = setup->array + j - begin;
    swap(setup->array + i, setup->array + j);

    SAVE_STATE(states, curr, temp);
  }

  // recursion on first half
  struct setup rec = { setup->array, i, setup->cmp };
  __quick(&rec, states, curr, begin);

  // recursion on second half
  rec.array = setup->array + i;
  rec.size = setup->size - i;
  __quick(&rec, states, curr, begin);
}

void __observe_quick(struct setup *setup, struct queue *states)
{
  struct state *curr = NULL;
  state_init(&curr);
  __quick(setup, states, curr, setup->array);
  state_free(&curr);
}