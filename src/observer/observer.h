
#ifndef OBSERVER_H
#define OBSERVER_H

#define SIGNATURE int *array, int size, int (*cmp)(int, int)

#include <string.h>

#include "../sort/sort.h"
#include "queue/queue.h"
#include "setup/setup.h"
#include "state/state.h"

struct queue *observe_bubble(SIGNATURE);

#endif /* ! OBSERVER_H */
