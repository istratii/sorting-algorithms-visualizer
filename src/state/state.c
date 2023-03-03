
#include "state.h"

void state_init(struct state **state)
{
  if (state == NULL)
    return;

  *state = calloc(1, sizeof(struct state));
}

void state_init_from(struct state **dst, struct state *src)
{
  if (dst == NULL)
    return;

  *dst = NULL;

  if (src == NULL)
    return;

  state_init(dst);
  memcpy(*dst, src, sizeof(struct state));
}

void state_free(struct state **state)
{
  if (state == NULL || *state == NULL)
    return;

  free(*state);
  *state = NULL;
}
