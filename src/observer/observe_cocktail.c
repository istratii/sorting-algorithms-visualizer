
#include "observer.h"

static int __left_to_right(struct setup *setup, struct queue *states, struct state *curr,
                           const int *begin)
{
  int done = 1;

  struct state *temp = NULL;
  ++(curr->comparisons);

  for (int i = 0; i < setup->size - 1; ++i)
  {
    RESET_SWAP_INDEXES(curr);
    curr->comparisons += 2;
    curr->accesses += 2;

    if (setup->cmp(setup->array[i], setup->array[i + 1]) > 0)
    {
      curr->swap_src = setup->array + i - begin;
      curr->swap_dst = setup->array + i + 1 - begin;
      ++(curr->swaps);
      swap(setup->array + i, setup->array + i + 1);
      done = 0;
    }

    SAVE_STATE(states, curr, temp);
  }

  return done;
}

static int __right_to_left(struct setup *setup, struct queue *states, struct state *curr,
                           const int *begin)
{
  int done = 1;

  struct state *temp = NULL;
  ++(curr->comparisons);

  for (int i = setup->size - 2; i > 0; --i)
  {
    RESET_SWAP_INDEXES(curr);
    curr->comparisons += 2;
    curr->accesses += 2;

    if (setup->cmp(setup->array[i], setup->array[i - 1]) < 0)
    {
      curr->swap_src = setup->array + i - begin;
      curr->swap_dst = setup->array + i - 1 - begin;
      ++(curr->swaps);
      swap(setup->array + i, setup->array + i - 1);
      done = 0;
    }

    SAVE_STATE(states, curr, temp);
  }

  return done;
}

void __observe_cocktail(struct setup *setup, struct queue *states)
{
  struct state *curr = NULL;
  state_init(&curr);

  int i = 0;

  while (42)
  {
    struct setup call = { setup->array + i, setup->size - i * 2, setup->cmp };

    if (__left_to_right(&call, states, curr, setup->array))
      break;

    if (__right_to_left(&call, states, curr, setup->array))
      break;

    ++i;
  }

  state_free(&curr);
}