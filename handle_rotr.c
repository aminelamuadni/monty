#include "monty.h"

/**
 * handle_rotr - Rotates the stack to the bottom.
 * @stack: A double pointer to the beginning of the stack.
 * @line_number: The line number of the current instruction.
 */
void handle_rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	(void)line_number;

	if (!*stack || !(*stack)->next)
		return;

	temp = *stack;

	while (temp->next && temp->next->next)
		temp = temp->next;

	temp->next->prev = NULL;
	temp->next->next = *stack;
	*stack = temp->next;
	temp->next = NULL;
}
