
#ifndef SORT_H
#define SORT_H

void bubble(int *array, int size, int (*comp)(int, int));
void insertion(int *array, int size, int (*comp)(int, int));
void swap(int *x, int *y);

#endif /* ! SORT_H */
