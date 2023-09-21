#include "monty.h"

/**
 * pall - Prints all values on the stack, starting from the top.
 * @stack: A double pointer to the head of the stack.
 * @line_number: The line number of the current opcode.
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	(void)line_number;

	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
