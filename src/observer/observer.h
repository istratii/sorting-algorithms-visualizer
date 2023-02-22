
#ifndef OBSERVER_H
#define OBSERVER_H

#include <string.h>

#include "../sort/sort.h"
#include "queue/queue.h"
#include "setup/setup.h"
#include "state/state.h"

typedef void (*observer)(struct setup *setup, struct queue *states);

#define OBSERVE_BUBBLE(Setup) observe(Setup, __observe_bubble)
#define OBSERVE_INSERTION(Setup) observe(Setup, __observe_insertion)
#define OBSERVE_SELECTION(Setup) observe(Setup, __observe_selection)
#define OBSERVE_QUICK(Setup) observe(Setup, __observe_quick)

#define SAVE_STATE(States, Curr, Temp)                                                             \
  state_init_from(&Temp, Curr);                                                                    \
  queue_push(States, Temp)

#define RESET_SWAP_INDEXES(State)                                                                  \
  (State)->swap_src = -1;                                                                          \
  (State)->swap_dst = -1

void __observe_bubble(struct setup *setup, struct queue *states);
void __observe_insertion(struct setup *setup, struct queue *states);
void __observe_selection(struct setup *setup, struct queue *states);
void __observe_quick(struct setup *setup, struct queue *states);
struct queue *observe(struct setup *setup, observer __observe);

#endif /* ! OBSERVER_H */
