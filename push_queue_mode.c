#include "monty.h"

/**
 * push_queue_mode - Adds a node to the end of a stack_t list.
 * @stack: A double pointer to the top of a stack.
 * @new_node: Node to add.
 */
void push_queue_mode(stack_t **stack, stack_t *new_node)
{
	stack_t *temp = *stack;

	if (!*stack)
	{
		*stack = new_node;
		return;
	}

	while (temp->next)
		temp = temp->next;

	temp->next = new_node;
	new_node->prev = temp;
}
