#include <stdio.h>
#include "../src/postfix.h"
#include "../lib/assert.h"

void
test_postfix_encode()
{
  char* expected = postfix_encode("((2*6)+(1/4))");
  assert_string("26*14/+", expected, "Expression completely surrounded by () without spaces");
}

int
main()
{
  test_postfix_encode();
}
