#include "monty.h"

/**
 * handle_pall - Handles the pall opcode.
 * @stack: A double pointer to the head of the stack.
 * @line_number: The line number of the current opcode.
 */
void handle_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	(void)line_number;

	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
