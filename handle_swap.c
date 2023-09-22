#include "monty.h"

/**
 * handle_swap - Swaps the top two elements of the stack.
 * @stack: A double pointer to the head of the stack.
 * @line_number: The current line number.
 */
void handle_swap(stack_t **stack, unsigned int line_number)
{
	int temp_val;

	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp_val = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp_val;
}
