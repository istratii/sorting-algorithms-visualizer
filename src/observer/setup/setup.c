
#include "setup.h"

void setup_init(struct setup **setup, int *array, int size)
{
  if (setup == NULL)
    return;

  *setup = malloc(sizeof(struct setup));

  if (*setup == NULL)
    return;

  (*setup)->array = array;
  (*setup)->size = size;
}

void setup_free(struct setup **setup)
{
  if (setup == NULL)
    return;

  free(*setup);
  *setup = NULL;
}