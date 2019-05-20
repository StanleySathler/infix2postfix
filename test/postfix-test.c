#include <stdio.h>
#include "../src/postfix.h"
#include "../lib/assert.h"

void
test_postfix_encode()
{
  char* actual;

  actual = postfix_encode("((2*6)+(1/4))");
  assert_string("26*14/+", actual, "Expression completely surrounded by ()");

  actual = postfix_encode("2+6*4-9");
  assert_string("264*+9-", actual, "Expression with different priorities");

  actual = postfix_encode("(2+8)*9");
  assert_string("28+9*", actual, "Expression with ()");

  actual = postfix_encode("(2 + 9)*12+(5/1)");
  assert_string("29+12*51/+", actual, "Expression with spaces");
}

int
main()
{
  test_postfix_encode();
}
