#ifndef __POSTFIX_H__
#define __POSTFIX_H__

  /**
   * @brief: Check if symbol is an operator.
   */
  static int
  is_operator(int operator);

  /**
   * @brief: Check if symbol is an operand.
   */
  static int
  is_operand(int operand);

  /**
   * @brief: Check the priority of the given operator.
   */
  static int
  priority(int operator);

  /**
   * @brief: Encode an expression to a postfix one.
   */
  char*
  postfix_encode(char* expression);

#endif /* __POSTFIX_H__ */
