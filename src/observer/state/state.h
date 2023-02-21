
#ifndef STATE_H
#define STATE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct state
{
  int accesses;
  int comparisons;
  int swaps;
  int swap_src;
  int swap_dst;
};

void state_init(struct state **state);
void state_init_from(struct state **dst, struct state *src);
void state_print(struct state *state);
void state_free(struct state **state);

#endif /* ! STATE_H */
