#include "monty.h"

/**
 * is_digit - Check if a given string is a valid integer.
 * @str: String to be checked.
 *
 * Return: 1 if string is a valid integer, otherwise 0.
 */
int is_digit(const char *str)
{
	if (!str)
		return (0);

	if (*str == '-' || *str == '+')
		str++;

	while (*str)
	{
		if (!isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

/**
 * free_stack - Frees the memory used by a doubly linked stack.
 * @stack: Head of the stack.
 *
 * Description: Iterates through each element of the stack
 * and frees the memory used by each node.
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

/**
 * execute_line - Processes a line of Monty bytecode.
 * @line: The line from the Monty bytecode file.
 * @stack: Double pointer to the beginning of the stack.
 * @line_number: The line number of the current instruction.
 *
 * Return: 0 if the line is processed without error, otherwise 1.
 */
int execute_line(char *line, stack_t **stack, unsigned int line_number)
{
	char *opcode, *argument;

	opcode = strtok(line, " \t\n");
	if (!opcode || opcode[0] == '#')
		return (0);

	argument = strtok(NULL, " \t\n");

	if (strcmp(opcode, "push") == 0)
	{
		if (push(stack, line_number, argument) == 1)
			return (1);
	}
	else if (strcmp(opcode, "pall") == 0)
	{
		pall(stack, line_number);
	}

	return (0);
}

/**
 * main - The primary function for the Monty interpreter.
 * @argc: Number of arguments passed to the program.
 * @argv: Array of arguments.
 *
 * Return: EXIT_SUCCESS on successful interpretation, otherwise EXIT_FAILURE.
 */
int main(int argc, char **argv)
{
	FILE *file;
	char line[1024];
	unsigned int line_number = 0;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (fgets(line, sizeof(line), file))
	{
		line_number++;
		execute_line(line, &stack, line_number);
	}

	free_stack(stack);
	fclose(file);

	return (EXIT_SUCCESS);
}
