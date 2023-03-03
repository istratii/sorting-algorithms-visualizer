
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "sort/sort.h"
#include "visualizer/visualizer.h"

#define OK 0
#define KO 1

#define BOUND 2500

static int __asc(int a, int b);
static int __des(int a, int b);
static int __prepare(const char *format);
static void __randomize(int *array, int size);
static void __sort(int *array, int size);

static int (*cmp)(int, int) = NULL;
static void (*sort)(int *, int, int (*)(int, int)) = NULL;
static int size = 0;

extern int *begin;
extern int done;
extern struct queue *states;
extern struct state *curr;

int main(int argc, char *argv[])
{
  if (argc <= 1)
  {
    fprintf(stderr, "main: usage: ./main [bBcCiIqQsS][aAdD][0-9]+\n");
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

  // init global vars
  begin = array;
  state_init(&curr);
  queue_init(&states);

  if (curr == NULL || states == NULL)
    return KO;

  __sort(array, size);

  // reproduce the sorting process graphically
  visualize(copy, size, states);

  queue_free(&states, free);
  return OK;
}

static int __asc(int a, int b)
{
  if (!done)
    UPDATE_CMP(curr);

  return a - b;
}

static int __des(int a, int b)
{
  if (!done)
    UPDATE_CMP(curr);

  return b - a;
}

static int __prepare_sort(char c)
{
  switch (c)
  {
  case 'b':
  case 'B':
    sort = bubble;
    break;
  case 'c':
  case 'C':
    sort = cocktail;
    break;
  case 'i':
  case 'I':
    sort = insertion;
    break;
  case 'q':
  case 'Q':
    sort = quick;
    break;
  case 's':
  case 'S':
    sort = selection;
    break;
  default:
    fprintf(stderr, "main: unknown sort, expect [bBcCiIqQsS]\n");
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
    fprintf(stderr, "main: unknown mode, expect [aAdD]\n");
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
  if (__prepare_sort(*format))
    return KO;

  if (__prepare_mode(*(format + 1)))
    return KO;

  if (__prepare_size(format + 2) < 0)
    return KO;

  return OK;
}

static void __randomize(int *array, int size)
{
  int deviation = rand() % (BOUND << 1);

  for (int i = 0; i < size; ++i)
    array[i] = rand() % (BOUND << 1) - deviation;
}

static void __sort(int *array, int size)
{
  // allow collecting data
  done = 0;

  // collect data
  sort(array, size, cmp);

  // disallow collecting data
  done = 1;
}
