#include "monty.h"

void add(Stack *stack) {
  if (stack->top < 2) {
    fprintf(stderr, "L%d: can't add, stack too short\n", __LINE__);
    exit(EXIT_FAILURE);
  }

  int top = stack->data[stack->top - 1];
  int second_top = stack->data[stack->top - 2];

  stack->data[stack->top - 2] = top + second_top;
  stack->top--;
}
