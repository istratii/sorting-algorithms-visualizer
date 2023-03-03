
#ifndef SORT_H
#define SORT_H

#define SIGNATURE int *array, int size, int (*cmp)(int, int)

#define UPDATE_SWAP(Begin, Src, Dst, Curr)                                                         \
  ++(Curr)->swaps;                                                                                 \
  (Curr)->swap_src = (Src) - (Begin);                                                              \
  (Curr)->swap_dst = (Dst) - (Begin)

#define UPDATE_CMP(Curr) ++(Curr)->comparisons

#define SAVE_STATE(States, Curr)                                                                   \
  struct state *temp = NULL;                                                                       \
  state_init_from(&temp, Curr);                                                                    \
  queue_push(States, temp)

#include <stdlib.h>
#include <string.h>

#include "queue/queue.h"
#include "state/state.h"

void bubble(SIGNATURE);
void insertion(SIGNATURE);
void selection(SIGNATURE);
void heap(SIGNATURE);
void count(SIGNATURE);
void merge(SIGNATURE);
void quick(SIGNATURE);
void cocktail(SIGNATURE);
void swap(int *x, int *y);

#endif /* ! SORT_H */
