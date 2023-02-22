
#include "observer.h"

struct queue *observe(struct setup *setup, observer_t __observe)
{
  struct queue *states = NULL;

  queue_init(&states);

  if (states != NULL)
    __observe(setup, states);

  return states;
}