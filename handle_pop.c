#include "monty.h"

/**
 * handle_pop - Remove the top element of the stack.
 * @stack: A double pointer to the head of the stack.
 * @line_number: The current line number.
 */
void handle_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = (*stack)->next;
	if (*stack)
		(*stack)->prev = NULL;
	free(temp);
}
