#include "monty.h"

/**
 * free_stack - Frees the memory used by a doubly linked stack.
 * @stack: Head of the stack.
 */
void free_stack(stack_t *stack)
{
	stack_t *temp;

	while (stack)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
}
