#include "monty.h"

/**
 * handle_rotl - Rotates the stack to the top.
 * @stack: A double pointer to the beginning of the stack.
 * @line_number: The line number of the current instruction.
 */
void handle_rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	(void)line_number;

	if (!*stack || !(*stack)->next)
		return;

	temp = *stack;

	while (temp->next)
		temp = temp->next;

	temp->next = *stack;
	(*stack)->prev = temp;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}
