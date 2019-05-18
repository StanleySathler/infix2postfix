#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include "postfix.h"
#include "../lib/stack.h"

/**
 * @brief: Check if symbol is an operator.
 */
int
is_operator(int operator)
{
  int multiplication = 42;
  int sum = 43;
  int subtraction = 45;
  int division = 47;

  return (
    operator == multiplication ||
    operator == sum ||
    operator == subtraction ||
    operator == division
  );
}

/**
 * @brief: Check if symbol is an operand.
 */
int
is_operand(int operand)
{
  return (
    operand > 47 &&
    operand < 58
  );
}

/**
 * @brief: Encode an expression to a postfix one.
 */
char*
postfix_encode(char* expression)
{
  stack_t operators = stack_create(strlen(expression));
  char* postfix = malloc(strlen(expression) * sizeof(char));
  int len_postfix = 0;

  for (int i = 0; expression[i]; i++) {

    /* For an operand, append it onto postfix expression */
    if (is_operand(expression[i]))
      postfix[len_postfix++] = expression[i];

    /* For an operator, push it into operators stack */
    else if (is_operator(expression[i]))
      stack_push(&operators, expression[i]);

    /* For an opening round bracket, just ignore it */
    else if (expression[i] == '(')
      continue;

    /* For a closing round bracket, add last operator onto postfix */
    else if (expression[i] == ')')
      postfix[len_postfix++] = stack_pop(&operators);
  }

  /* Finish postfix string with a null char */
  postfix[len_postfix] = '\0';

  return postfix;
}


