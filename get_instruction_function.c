#include "monty.h"

/**
 * get_instruction_function - Finds and returns the function to be executed
 * @opcode: The opcode to find.
 *
 * Return: Pointer to the required function, or NULL if no opcode matches.
 */
void (*get_instruction_function(char *opcode))(stack_t **, unsigned int)
{
	int i;

	instruction_t functions[] = {
		{"pall", handle_pall},
		{"pint", handle_pint},
		{"pop", handle_pop},
		{"swap", handle_swap},
		{"add", handle_add},
		{"nop", handle_nop},
		{"sub", handle_sub},
		{"div", handle_div},
		{"mul", handle_mul},
		{"mod", handle_mod},
		{"pchar", handle_pchar},
		{"pstr", handle_pstr},
		{"rotl", handle_rotl},
		{"rotr", handle_rotr},
		{"stack", handle_stack},
		{"queue", handle_queue},
		{NULL, NULL}
	};

	for (i = 0; functions[i].opcode; i++)
	{
		if (strcmp(opcode, functions[i].opcode) == 0)
			return (functions[i].f);
	}

	return (NULL);
}
