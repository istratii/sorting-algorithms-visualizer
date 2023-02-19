
#include <criterion/criterion.h>

#include "../src/sort/sort.h"
#include "utils.h"

Test(test_bubble, bubble)
{
  cr_expect(check(bubble, "Bubble", ASC_DES));
  cr_expect(check(insertion, "Insertion", ASC_DES));
  cr_expect(check(selection, "Selection", ASC_DES));
  cr_expect(check(heap, "Heap", ASC_DES));
  cr_expect(check(count, "Count", ASC));
}