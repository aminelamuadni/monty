#include "monty.h"

/**
 * push_stack_mode - Adds a node to the top of a stack_t list.
 * @stack: A double pointer to the top of a stack.
 * @new_node: Node to add.
 */
void push_stack_mode(stack_t **stack, stack_t *new_node)
{
	if (*stack)
	{
		new_node->next = *stack;
		(*stack)->prev = new_node;
	}
	*stack = new_node;
}
