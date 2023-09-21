#include "monty.h"

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

		if (execute_line(line, &stack, line_number) != 0)
		{
			free_stack(stack);
			fclose(file);
			exit(EXIT_FAILURE);
		}
	}

	free_stack(stack);
	fclose(file);

	return (EXIT_SUCCESS);
}
