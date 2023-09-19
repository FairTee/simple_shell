#include "shell.h"
/**
 * shell_exit - Exit the custom shell with an optional exit code
 * @argument: arguments provided by the user
 * @input_line: input line from the user
 * @exit_code: exit code to use
 * Return: 0
 */
void shell_exit(char **argument, char *input_line, int exit_code)
{
	int just_exit = 0;


	if (!argument[1])
	{
		free(input_line);
		free(argument);
		exit(exit_code);
	}
	just_exit = atoi(argument[1]);

	free(input_line);
	free(argument);
	exit(just_exit);
}

/**
 * print_env - Prints the enivironment variables to stdout
 * @environ: environment variables to print
 * Return: 0
 */

void print_env(char **environ)
{
	size_t index = 0;

	while (environ[index])
	{
		write(STDOUT_FILENO, environ[index], string_length(environ[index]));
		write(STDOUT_FILENO, "\n", 1);
		index++;
	}
}
