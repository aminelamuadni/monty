#include "monty.h"

/**
 * push - Pushes an integer onto the top of the stack.
 * @stack: A double pointer to the head of the stack.
 * @line_number: The line number of the current opcode.
 * @n_str: The string representation of the integer to be pushed.
 *
 * Return: 0 on success, 1 on error.
 */
int push(stack_t **stack, unsigned int line_number, const char *n_str)
{
	stack_t *new_node;

	if (!n_str || !is_digit(n_str))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		return (1);
	}

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	new_node->n = atoi(n_str);
	new_node->next = *stack;
	new_node->prev = NULL;
	if (*stack)
		(*stack)->prev = new_node;
	*stack = new_node;

	return (0);
}
