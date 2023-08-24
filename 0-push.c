#include "monty.h"
<<<<<<< HEAD
/**
 * f_push - add node to the stack
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void f_push(stack_t **head, unsigned int counter)
{
	int n, j = 0, flag = 0;

	if (bus.arg)
	{
		if (bus.arg[0] == '-')
			j++;
		for (; bus.arg[j] != '\0'; j++)
		{
			if (bus.arg[j] > 57 || bus.arg[j] < 48)
				flag = 1; }
		if (flag == 1)
		{ fprintf(stderr, "L%d: usage: push integer\n", counter);
			fclose(bus.file);
			free(bus.content);
			free_stack(*head);
			exit(EXIT_FAILURE); }}
	else
	{ fprintf(stderr, "L%d: usage: push integer\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE); }
	n = atoi(bus.arg);
	if (bus.lifi == 0)
		addnode(head, n);
	else
		addqueue(head, n);
=======

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

  (*head)->data[(*head)->top++] = value;
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
>>>>>>> 1eaf145b9f706505b5cba63d500b08abee119141
}

