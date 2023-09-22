#include "monty.h"

/**
 * handle_pstr - Prints the string starting at the top of the stack.
 * @stack: A double pointer to the beginning of the stack.
 * @line_number: The line number of the current instruction.
 */
void handle_pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	(void)line_number;

	while (temp)
	{
		if (temp->n <= 0 || temp->n > 127)
			break;

		putchar(temp->n);
		temp = temp->next;
	}
	putchar('\n');
}
