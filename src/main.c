
#include <stdio.h>

#include "sort/sort.h"

int comp(int a, int b)
{
  return a - b;
}

int main(void)
{
  int arr[] = { 1, 2, 5, 4, 3 };
  insertion(arr, 5, comp);
  for (int i = 0; i < 5; ++i)
    printf("%d\n", arr[i]);
  return 0;
}
