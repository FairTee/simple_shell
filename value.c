#include "shell.h"

/**
 * find_executable - Find an executable file in the path environment
 * @command: the command input by the user
 * @envir: environment
 * Return: 0
 */
int find_executable(char **command, char **envir)
{
	char *souv = NULL, *late = NULL, *lute = NULL;
	size_t find_exec, cmd;
	struct stat stat_info;

	if (sta(*command, &stat_info) == 0)
		return (-1);
	late = net_path_from_env(envir);
	if (!late)
		return (-1);
	souv = tokenize_string(late, ":");
	cmd = string_length(*command);
	while (souv)
	{
		find_exec = string_length(souv);
		lute = malloc(sizeof(char) * (find_exec + cmd + 2));
		if (!lute)
		{
			free(late);
			return (-1);
		}
		lute = string_copy(lute, souv);
		string_concat(lute, "/");
		string_concat(lute, *command);

		if (stat(lute, &stat_info) == 0)
		{
			*command = lute;
			free(late);
			return (0);
		}
		free(lute);
		souv = tokenize_string(NULL, ":");
	}
	free(late);
	return (-1);
}

