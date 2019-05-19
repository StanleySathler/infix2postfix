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
 * @brief: Check the priority of the given operator.
 */
int
priority(int operator)
{
  switch (operator) {
    case '(': return 0;
    case '+':
    case '-': return 1;
    case '*':
    case '/': return 2;
  }

  return -1;
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

    /* For an operator, while there is another operator
     * with higher or equal priority in the stack, we must
     * pop it and append onto the expression, to only then
     * push the current operator into the operators stack.
     */
    else if (is_operator(expression[i])) {
      while (!stack_is_empty(&operators) && priority(stack_top(&operators)) >= priority(expression[i]))
        postfix[len_postfix++] = stack_pop(&operators);
      stack_push(&operators, expression[i]);
    }

    /* For an opening round bracket, push it into stack - as it has
     * priority 0
     */
    else if (expression[i] == '(')
      stack_push(&operators, expression[i]);

    /* For a closing round bracket, pop all operators from
     * stack until an opening round bracket is found. Then,
     * pop the opening round bracket and discard it.
     */
    else if (expression[i] == ')') {
      while (stack_top(&operators) != '(')
        postfix[len_postfix++] = stack_pop(&operators);
      stack_pop(&operators);
    }
  }

  /* Pop anything left in operators stack */
  while (!stack_is_empty(&operators))
    postfix[len_postfix++] = stack_pop(&operators);

  /* Finish postfix string with a null char */
  postfix[len_postfix] = '\0';

  return postfix;
}


