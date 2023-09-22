#include "monty.h"

/**
 * handle_pint - Print the value at the top of the stack.
 * @stack: A double pointer to the head of the stack.
 * @line_number: The current line number.
 */
void handle_pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}
