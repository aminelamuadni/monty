#include "monty.h"

/**
 * free_stack - Frees a doubly linked stack.
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

/**
 * execute_line - Processes and executes a line.
 * @line: The line to process.
 * @stack: Head of the stack.
 * @line_number: The current line number.
 */
void execute_line(char *line, stack_t **stack, unsigned int line_number)
{
	char *opcode = strtok(line, "\n\t\r ");
	char *n_str;

	if (opcode == NULL || opcode[0] == '#')
		return;

	if (strcmp(opcode, "push") == 0)
	{
		n_str = strtok(NULL, "\n\t\r ");

		if (n_str == NULL || (atoi(n_str) == 0 && n_str[0] != '0'))
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}

		push(stack, line_number, n_str);
	}
	else if (strcmp(opcode, "pall") == 0)
	{
		pall(stack, line_number);
	}
}

/**
 * main - Entry point of Monty interpreter.
 * @argc: Number of arguments passed.
 * @argv: Array of arguments.
 *
 * Return: EXIT_SUCCESS on success or EXIT_FAILURE on failure.
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

	while (fgets(line, sizeof(line), file) != NULL)
	{
		line_number++;
		execute_line(line, &stack, line_number);
	}

	free_stack(stack);
	fclose(file);

	return (EXIT_SUCCESS);
}
