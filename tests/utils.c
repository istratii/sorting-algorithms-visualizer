
#include "utils.h"

#define SIZE 20

#define CHECK(Ref, Out, Size, Sort, Comparator, Check, Debug, Name, Status)                                            \
  memcpy(Out, Ref, Size * sizeof(int));                                                                                \
  Sort(Out, Size, Comparator);                                                                                         \
  if (!Check(Out, Size))                                                                                               \
  {                                                                                                                    \
    fprintf(stderr, "%s FAILED\n", Name);                                                                              \
    Debug(Ref, Out, Size);                                                                                             \
    Status = 0;                                                                                                        \
  }

static int N[][SIZE] = {
  { 58, -25, 7, -49, 13, -87, -107, 50, -67, -49, 14, -96, -96, -10, -3, -63, 89, 47, 112, -74 },
  { 29, -99, 89, -109, 21, -96, -98, -12, -78, 114, 89, -103, 22, -77, -29, 66, -81, -88, 19, -103 },
  { 12, 95, -16, -112, -100, -31, 91, 52, -56, -85, 15, -75, -74, -1, -96, 113, -29, -45, -110, -18 },
  { -74, 30, -60, 42, 71, -107, -111, -27, -81, 77, -17, -54, 10, 106, -119, 23, 120, 62, -9, -7 },
  { -30, 60, -24, -103, 58, -32, -40, 10, 27, -69, 34, 49, 119, -18, -52, 15, 81, -44, 48, 6 },
  { -87, 0, 61, 28, 56, 67, -52, 41, -102, -83, -21, -116, 93, -49, 27, 6, 100, 37, 30, 73 },
  { 14, -99, -45, -107, -94, -107, 52, 46, -118, -71, 6, -59, 104, 5, 33, 55, 73, -88, 63, -3 },
  { -83, 100, -69, 100, -22, -24, 37, 111, -114, 49, -102, -52, -21, -80, -18, -14, -37, 80, -105, -111 },
  { 83, -29, -84, 7, 3, -113, -30, -106, -56, -35, -17, -78, 119, -87, -27, 50, -40, -99, -90, -19 },
  { 57, -59, -72, -46, -13, -92, 31, -49, -81, -97, -77, -117, -24, -77, -46, -21, -98, 14, -16, 82 },
  { 1, 44, -119, -9, 76, -63, -71, -21, -24, 112, 33, 0, -16, 67, 85, 44, -78, 112, 42, -54 },
  { 22, 94, -8, 47, -55, -28, -108, -87, -79, -71, 59, 69, 111, -114, 58, -43, 61, -47, 34, -5 },
  { -104, -55, -84, 83, -65, -119, -70, -117, -32, 99, 79, -98, -102, 117, -90, 4, -49, -111, 56, 77 },
  { -45, 88, 65, -21, -95, 90, 17, 42, -117, 115, 33, 83, 19, -97, -56, -106, 30, -22, 52, -39 },
  { 74, -27, -107, 26, -72, 115, 86, 25, 43, 56, -87, 99, 72, -85, -60, -120, 20, -29, -7, -44 },
  { -13, -36, 59, 81, -52, 73, -116, -118, 106, 25, 60, -36, -110, 93, -117, 95, -39, 116, -32, 60 },
  { 10, -7, -9, -58, -31, -104, -73, -79, 19, -107, 64, 73, -57, -73, 97, -2, -26, 69, -96, 96 },
  { -10, -106, -16, -44, 85, -98, 79, -22, -61, 85, -103, -115, 85, 32, -65, -82, 17, -25, 84, 92 },
  { 92, -18, -28, 86, 105, 74, 95, -56, -104, 29, 65, 62, 29, 54, -88, 27, 106, 78, -14, 20 },
  { 15, 69, -79, -101, 78, 36, 93, 109, -79, 88, -35, 107, 65, -24, -111, -69, 53, 58, 118, 65 }
};

static int __asc(int a, int b)
{
  return a - b;
}

static int __des(int a, int b)
{
  return b - a;
}

static int __check_asc(int *array, int size)
{
  for (int i = 0; i + 1 < size; ++i)
    if (array[i] > array[i + 1])
      return 0;

  return 1;
}

static int __check_des(int *array, int size)
{
  for (int i = 0; i + 1 < size; ++i)
    if (array[i] < array[i + 1])
      return 0;

  return 1;
}

static void __print_array(int *array, int size)
{
  if (size < 1)
    return;

  fprintf(stderr, "%d", array[0]);

  for (int i = 1; i < size; ++i)
    fprintf(stderr, " %d", array[i]);

  fprintf(stderr, "\n");
}

static void __debug(int *expected, int *got, int size)
{
  fprintf(stderr, "Expected: ");
  __print_array(expected, size);

  fprintf(stderr, "Got: ");
  __print_array(expected, size);
}

int check(void (*sort)(int *, int, int (*comp)(int, int)), char *algname)
{
  int ok = 1;

  for (int i = 0; i < SIZE; ++i)
  {
    int array[SIZE];

    CHECK(N[i], array, SIZE, sort, __asc, __check_asc, __debug, algname, ok);
    CHECK(N[i], array, SIZE, sort, __des, __check_des, __debug, algname, ok);
  }

  return ok;
}
