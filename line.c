#include "shell.h"

/**
 * read_user_input - Read user input from stdin.
 * Return: ptr to input line
 */

char *read_user_input(void)
{
	char *input = NULL;
	size_t input_length = 0;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);

	if (getline(&input, &input_length, stdin) == -1)
	{
		free(input);
		return (NULL);
	}

	return (input);
}
