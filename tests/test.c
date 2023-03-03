
#include <criterion/criterion.h>

#include "sort/sort.h"
#include "utils.h"

#define CONCAT(A, B) A##B
#define TEST_CASE(Func, Mode)                                                                      \
  Test(CONCAT(test_, Func), CONCAT(Func, _sort))                                                   \
  {                                                                                                \
    cr_assert(check(Func, Mode));                                                                  \
  }

TEST_CASE(bubble, MODE_BOTH)
TEST_CASE(cocktail, MODE_BOTH)
TEST_CASE(count, MODE_ASC)
TEST_CASE(heap, MODE_BOTH)
TEST_CASE(insertion, MODE_BOTH)
TEST_CASE(merge, MODE_BOTH)
TEST_CASE(selection, MODE_BOTH)
TEST_CASE(quick, MODE_BOTH)