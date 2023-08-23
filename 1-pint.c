#include "monty.h"

void pint(Stack *stack) {
  if (stack->top == 0) {
    fprintf(stderr, "L%d: can't pint, stack empty\n", __LINE__);
    exit(EXIT_FAILURE);
  }

  printf("%d\n", stack->data[stack->top - 1]);
}
