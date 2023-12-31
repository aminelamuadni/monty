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
	void (*function)(stack_t **, unsigned int);

	opcode = strtok(line, " \t\n");
	if (!opcode || opcode[0] == '#')
		return (0);

	argument = strtok(NULL, " \t\n");

	if (strcmp(opcode, "push") == 0)
	{
		handle_push(stack, line_number, argument);
		return (0);
	}

	function = get_instruction_function(opcode);
	if (function)
	{
		function(stack, line_number);
		return (0);
	}

	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
	exit(EXIT_FAILURE);
}
