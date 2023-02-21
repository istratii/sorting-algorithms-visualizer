
#ifndef SETUP_H
#define SETUP_H

#include <stdlib.h>

struct setup
{
  int *array;
  int size;
};

void setup_init(struct setup **setup, int *array, int size);
void setup_free(struct setup **setup);

#endif /* ! SETUP_H */
