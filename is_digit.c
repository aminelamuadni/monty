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
		if (!isdigit((unsigned char)*str))
			return (0);
		str++;
	}
	return (1);
}
