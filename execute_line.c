#include "monty.h"

/**
 * execute_line - Executes a line of Monty bytecode
 * @line: The line from the Monty bytecode file.
 * @stack: A double pointer to the beginning of the stack.
 * @line_number: The line number of the current instruction.
 *
 * Return: 0 if the line is processed without error, otherwise 1.
 */
int execute_line(char *line, stack_t **stack, unsigned int line_number)
{
	char *opcode, *argument;
	int i;

	instruction_t functions[] = {
		{"pall", handle_pall},
		{"pint", handle_pint},
		{"pop", handle_pop},
		{"swap", handle_swap},
		{"add", handle_add},
		{"add", handle_nop},
		{NULL, NULL}
	};

	opcode = strtok(line, " \t\n");
	if (!opcode || opcode[0] == '#')
	{
		return (0);
	}

	argument = strtok(NULL, " \t\n");

	if (strcmp(opcode, "push") == 0)
	{
		handle_push(stack, line_number, argument);
		return (0);
	}

	for (i = 0; functions[i].opcode; i++)
	{
		if (strcmp(opcode, functions[i].opcode) == 0)
		{
			functions[i].f(stack, line_number);
			return (0);
		}
	}

	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
	exit(EXIT_FAILURE);

	return (0);
}
