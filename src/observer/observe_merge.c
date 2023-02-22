
#include "observer.h"

static void __merge(struct setup *setup, struct queue *states, struct state *curr, const int *begin)
{
  struct state *temp = NULL;

  RESET_SWAP_INDEXES(curr);
  ++(curr->comparisons);

  if (setup->size == 0)
  {
    SAVE_STATE(states, curr, temp);
    return;
  }

  int *out = malloc(setup->size * sizeof(int));
  int *tmp = out;
  int i = 0;
  int j = setup->size >> 1;

  while (i < (setup->size >> 1) && j < setup->size)
  {
    curr->comparisons += 2;
    curr->accesses += 4;

    if (setup->cmp(setup->array[i], setup->array[j]) < 0)
      *(tmp++) = setup->array[i++];

    else
      *(tmp++) = setup->array[j++];

    SAVE_STATE(states, curr, temp);
  }

  // above while loop end conditions
  // below two while loop end conditions
  curr->comparisons += (i < (setup->size >> 1)) + 3;

  while (i < (setup->size >> 1))
  {
    curr->accesses += 2;
    ++(curr->comparisons);
    *(tmp++) = setup->array[i++];

    SAVE_STATE(states, curr, temp);
  }

  while (j < setup->size)
  {
    curr->accesses += 2;
    ++(curr->comparisons);
    *(tmp++) = setup->array[j++];

    SAVE_STATE(states, curr, temp);
  }

  memcpy(setup->array, out, setup->size * sizeof(int));
  free(out);
}

static void __sort(struct setup *setup, struct queue *states, struct state *curr, const int *begin)
{
  if (setup->size <= 1)
    return;

  struct setup rec = { setup->array, setup->size >> 1, setup->cmp };
  __sort(&rec, states, curr, begin);

  rec.array = setup->array + (setup->size >> 1);
  rec.size = setup->size - (setup->size >> 1);
  __sort(&rec, states, curr, begin);

  __merge(setup, states, curr, begin);
}

static void __observe_merge(struct setup *setup, struct queue *states)
{
  struct state *curr = NULL;
  state_init(&curr);
  RESET_SWAP_INDEXES(curr);

  __sort(setup, states, curr, setup->array);

  state_free(&curr);
}