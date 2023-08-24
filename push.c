#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct Stack {
  int data[STACK_SIZE];
  int top;
} Stack;

void f_push(Stack **head, unsigned int counter) {
  int value;

  value = counter;

  if (*head == NULL) {
    *head = malloc(sizeof(Stack));
    if (*head == NULL) {
      printf("Error: malloc failed\n");
      exit(EXIT_FAILURE);
    }

    (*head)->top = 0;
  }

  (*head)->data[++(*head)->top] = value;
}

int main(void) {
  Stack *head = NULL;
  unsigned int counter;

  for (counter = 1; counter <= 10; counter++) {
    f_push(&head, counter);
  }

  while (head != NULL) {
    printf("%d\n", head->data[head->top - 1]);
    head = head->next;
  }

  return 0;
}
