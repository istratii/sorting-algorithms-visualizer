
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "observer/observer.h"
#include "sort/sort.h"
#include "visualizer/visualizer.h"

#define OK 0
#define KO 1

#define BOUND 2500

static int __asc(int a, int b);
static int __des(int a, int b);
static int __prepare(const char *format);
static void __randomize(int *array, int size);

static int (*cmp)(int, int) = NULL;
static observer_t observer = NULL;
static int size = 0;

int main(int argc, char *argv[])
{
  if (argc <= 1)
  {
    fprintf(stderr, "main: usage: ./main format\n");
    return KO;
  }

  srand(time(NULL));

  if (__prepare(argv[1]))
    return KO;

  if (size == 0)
    return OK;

  if (size > WIDTH)
    return KO;

  int array[WIDTH];
  int copy[WIDTH];

  __randomize(array, size);
  memcpy(copy, array, size * sizeof(int));

  struct setup setup = { array, size, cmp };
  struct queue *states = observe(&setup, observer);

  if (states == NULL)
    return KO;

  visualize(copy, size, states);

  queue_free(&states, free);
  return OK;
}

static int __asc(int a, int b)
{
  return a - b;
}

static int __des(int a, int b)
{
  return b - a;
}

static int __prepare_observer(char c)
{
  switch (c)
  {
  case 'b':
  case 'B':
    observer = __observe_bubble;
    break;
  case 'c':
  case 'C':
    observer = __observe_cocktail;
    break;
  case 'i':
  case 'I':
    observer = __observe_insertion;
    break;
  case 'q':
  case 'Q':
    observer = __observe_quick;
    break;
  case 's':
  case 'S':
    observer = __observe_selection;
    break;
  default:
    fprintf(stderr, "main: unknown observer, expect (b|B|c|C|i|I|q|Q|s|S)\n");
    return KO;
  }

  return OK;
}

static int __prepare_mode(char c)
{
  if (c == 'a' || c == 'A')
    cmp = __asc;

  else if (c == 'd' || c == 'D')
    cmp = __des;

  else
  {
    fprintf(stderr, "main: unknown mode, expect (a|A|d|D)\n");
    return KO;
  }

  return OK;
}

static int __prepare_size(const char *s)
{
  while (*s != 0 && isdigit(*s))
    size = size * 10 + *(s++) - '0';

  return *s != 0;
}

static int __prepare(const char *format)
{
  if (__prepare_observer(*format))
    return KO;

  if (__prepare_mode(*(format + 1)))
    return KO;

  if (__prepare_size(format + 2) < 0)
    return KO;

  return OK;
}

static void __randomize(int *array, int size)
{
  int deviation = BOUND - rand() % BOUND;

  for (int i = 0; i < size; ++i)
    array[i] = rand() % (BOUND << 1) - deviation;
}
