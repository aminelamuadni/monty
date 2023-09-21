#include "monty.h"

/**
 * handle_push - Handles the push opcode
 * @stack: A double pointer to the head of the stack.
 * @line_number: The line number where the instruction appears.
 * @argument: The argument given with the push opcode.
 */
void handle_push(stack_t **stack, unsigned int line_number, char *argument)
{
	stack_t *new_node;

	if (!argument || !is_digit(argument))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE); 
	}

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = atoi(argument);
	new_node->next = *stack;
	new_node->prev = NULL;
	if (*stack)
		(*stack)->prev = new_node;
	*stack = new_node;
}
