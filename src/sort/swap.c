
#include "sort.h"

int *begin = NULL;
int done = 1;
struct queue *states = NULL;
struct state *curr = NULL;

void swap(int *x, int *y)
{
  if (!done)
  {
    UPDATE_SWAP(begin, x, y, curr);
    SAVE_STATE(states, curr);
  }

  int t = *x;
  *x = *y;
  *y = t;
}