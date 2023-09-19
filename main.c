#include "shell.h"

/**
 * main - Entry
 * @on: arguments count
 * @in: arguments
 * @envir: said environment
 * Return: 0
 */
int main(int on, char **in, char **envir)
{
	char *take_input, **rec_input = NULL;
	int valuation = 0, end = 0, q = 0;
	(void)on;

	while (1)
	{
		take_input = read_user_input();
		if (take_input)
		{
			valuation++;
			rec_input = tokenize_input(take_input);
			if (!rec_input)
			{
				free(take_input);
				continue;
			}
			if ((!strin_compare(rec_input[0], "exit")) && rec_input[1] == NULL)
				shell_exit(rec_input, take_input, end);
			if (!strin_compare(rec_input[0], "envir"))
				print_env(envir);
			else
			{
				q = find_executable(&rec_input[0], envir);
				end = fork_execute(rec_input, in, envir, take_input, valuation, q);
				if (q == 0)
					free(rec_input[0]);
			}
			free(rec_input);
		}
		else
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			exit(end);
		}
		free(take_input);
	}
	return (end);
}
