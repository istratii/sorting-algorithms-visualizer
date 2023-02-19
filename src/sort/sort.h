
#ifndef SORT_H
#define SORT_H

#define SIGNATURE int *array, int size, int (*cmp)(int, int)

#include <stdlib.h>
#include <string.h>

void bubble(SIGNATURE);
void insertion(SIGNATURE);
void selection(SIGNATURE);
void heap(SIGNATURE);
void count(SIGNATURE);
void merge(SIGNATURE);
void quick(SIGNATURE);
void cocktail(SIGNATURE);
void swap(int *x, int *y);

#endif /* ! SORT_H */
