#include "monty.h"

/**
 * handle_pchar - Prints the char at the top of the stack.
 * @stack: A double pointer to the beginning of the stack.
 * @line_number: The line number of the current instruction.
 */
void handle_pchar(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", (*stack)->n);
}
