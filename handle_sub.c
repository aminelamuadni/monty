#include "monty.h"

/**
 * handle_sub - subtracts the top element from the second top element.
 * @stack: A double pointer to the beginning of the stack.
 * @line_number: The line number of the current instruction.
 */
void handle_sub(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	tmp = *stack;
	(*stack) = (*stack)->next;
	(*stack)->n -= tmp->n;
	(*stack)->prev = NULL;
	free(tmp);
}
