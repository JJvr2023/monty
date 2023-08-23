#include "monty.h"

void swap(Stack *stack) {
  if (stack->top < 2) {
    fprintf(stderr, "L%d: can't swap, stack too short\n", __LINE__);
    exit(EXIT_FAILURE);
  }

  int temp = stack->data[stack->top - 1];
  stack->data[stack->top - 1] = stack->data[stack->top - 2];
  stack->data[stack->top - 2] = temp;
}
