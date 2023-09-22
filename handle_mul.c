#include "monty.h"

/**
 * handle_mul - Multiplies the second top element by the top element of the stack.
 * @stack: A double pointer to the beginning of the stack.
 * @line_number: The line number of the current instruction.
 */
void handle_mul(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n *= (*stack)->n;

	temp = *stack;
	*stack = (*stack)->next;
	free(temp);
}
