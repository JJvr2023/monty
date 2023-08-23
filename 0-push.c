#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

#define STACK_SIZE 100

typedef struct {
  int data[STACK_SIZE];
  int top;
} Stack;

void push(Stack *stack, int value) {
  if (stack->top == STACK_SIZE) {
    printf("Error: stack overflow\n");
    exit(EXIT_FAILURE);
  }

  stack->data[stack->top++] = value;
}

void pall(Stack *stack) {
  int i;

  if (stack->top == 0) {
    return;
  }

  for (i = stack->top - 1; i >= 0; i--) {
    printf("%d\n", stack->data[i]);
  }
}

int main(int argc, char *argv[]) {
  Stack stack;
  char *line;
  int value;

  stack.top = 0;

  while (1) {
    line = get_line();
    if (line == NULL) {
      break;
    }
    value = atoi(line);
    if (value == -1) {
      printf("Error: invalid integer\n");
      exit(EXIT_FAILURE);
    }

    if (strcmp(line, "push") == 0) {
      push(&stack, value);
    } else if (strcmp(line, "pall") == 0) {
      pall(&stack);
    } else {
      printf("Error: unknown opcode %s\n", line);
      exit(EXIT_FAILURE);
    }

    free(line);
  }

  return 0;
}
