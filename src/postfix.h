#ifndef __POSTFIX_H__
#define __POSTFIX_H__

  /**
   * @brief: Check if symbol is an operator.
   */
  int
  get_operator(int operator);

  /**
   * @brief: Check if symbol is an operand.
   */
  int
  get_operand(int operand);

  /**
   * @brief: Encode an expression to a postfix one.
   */
  char*
  postfix_encode(char* expression);

#endif /* __POSTFIX_H__ */
