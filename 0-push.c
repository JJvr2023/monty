#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

typedef struct Stack {
  int data[STACK_SIZE];
  int top;
} stack_t;

void push(stack_t *stack, int value) {
  if (stack->top == STACK_SIZE) {
    printf("Error: stack overflow\n");
    exit(EXIT_FAILURE);
  }

  stack->data[stack->top++] = value;
}

void pall(stack_t *stack) {
  int i;

  if (stack->top == 0) {
    return;
  }

  for (i = stack->top - 1; i >= 0; i--) {
    printf("%d\n", stack->data[i]);
  }
}

void pint(stack_t *stack) {
  if (stack->top == 0) {
    printf("Error: can't pint, stack empty\n");
    exit(EXIT_FAILURE);
  }

  printf("%d\n", stack->data[stack->top - 1]);
}

void pop(stack_t *stack) {
  if (stack->top == 0) {
    printf("Error: can't pop an empty stack\n");
    exit(EXIT_FAILURE);
  }

  stack->top--;
}

void swap(stack_t *stack) {
  if (stack->top < 2) {
    printf("Error: can't swap, stack too short\n");
    exit(EXIT_FAILURE);
  }

  int temp = stack->data[stack->top - 1];
  stack->data[stack->top - 1] = stack->data[stack->top - 2];
  stack->data[stack->top - 2] = temp;
}

void add(stack_t *stack) {
  if (stack->top < 2) {
    printf("Error: can't add, stack too short\n");
    exit(EXIT_FAILURE);
  }

  int top = stack->data[stack->top - 1];
  int second_top = stack->data[stack->top - 2];

  stack->data[stack->top - 2] = top + second_top;
  stack->top--;
}

int main(int argc, char *argv[]) {
  stack_t stack;
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

    switch (line[0]) {
      case 'p':
        if (line[1] == 'a') {
          pall(&stack);
        } else if (line[1] == 'i') {
          pint(&stack);
        } else {
          printf("Error: unknown opcode %s\n", line);
          exit(EXIT_FAILURE);
        }
        break;
      case 's':
        swap(&stack);
        break;
      case 'a':
        add(&stack);
        break;
      case 'd':
        pop(&stack);
        break;
      case 'c':
        break;
      default:
        printf("Error: unknown opcode %s\n", line);
        exit(EXIT_FAILURE);
    }

    free(line);
  }

  return 0;
}
