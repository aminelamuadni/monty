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
	char *opcode = NULL;
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

		opcode = strtok(line, "\n\t\r ");
		if (opcode == NULL || opcode[0] == '#')
			continue;

		if (strcmp(opcode, "push") == 0)
		{
			char *n_str = strtok(NULL, "\n\t\r ");
			push(&stack, line_number, n_str);
		}
		else if (strcmp(opcode, "pall") == 0)
		{
			pall(&stack, line_number);
		}
	}

	free_stack(stack);
	fclose(file);

	return (EXIT_SUCCESS);
}
