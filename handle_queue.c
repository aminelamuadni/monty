#include "monty.h"

/**
 * handle_queue - Sets the mode to queue.
 * @stack: A double pointer to the beginning of the stack.
 * @line_number: The line number of the current instruction.
 */
void handle_queue(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;

	mode = 1;
}
