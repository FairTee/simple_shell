#include "shell.h"

/**
 * fork_execute - Fork a child process and execute a command
 * @argmt: arguments to execute
 * @pn: name of the program being executed
 * @envr: environment
 * @input: input line from the user
 * @pid: Process ID
 * @cf: Flag to check
 * Return: 0 success
 */

int fork_execute(char **argmt, char **pn, char **envr,
		char *input, int pid, int cf)
{
	pid_t chill;
	int ex_stat;
	char *errf = "%s: %d: %s: not found\n";

	chill = fork();

	if (chill == 0)
	{
		if (execve(argmt[0], argmt, envr) == -1)
		{
			fprintf(stderr, errf, pn[0], pid, argmt[0]);
			if (!cf)
				free(argmt[0]);
			free(argmt);
			free(input);
			exit(errno);
		}
	}
	else
	{
		wait(&ex_stat);

		if (WIFEXITED(ex_stat) && WEXITSTATUS(ex_stat) != 0)
			return (WEXITSTATUS(ex_stat));
	}
	return (0);
}
