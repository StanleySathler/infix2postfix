#include <stdio.h>
#include "../src/postfix.h"
#include "../lib/assert.h"

void
test_postfix_encode()
{
  char* actual;

  actual = postfix_encode("((2*6)+(1/4))");
  assert_string("26*14/+", actual, "Expression completely surrounded by () without spaces");

  actual = postfix_encode("2+6*4-9");
  assert_string("264*+9-", actual, "Expression without () nor spaces and with priorities");

  actual = postfix_encode("(2+8)*9");
  assert_string("28+9*", actual, "Expression with ()");
}

int
main()
{
  test_postfix_encode();
}
