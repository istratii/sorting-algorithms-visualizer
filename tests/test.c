
#include <criterion/criterion.h>

#include "../src/sort/sort.h"
#include "utils.h"

Test(test_bubble, bubble)
{
  cr_expect(check(bubble, "Bubble"));
  cr_expect(check(insertion, "Insertion"));
}