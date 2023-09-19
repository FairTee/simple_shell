#include "shell.h"

/**
 * net_path_from_env - Net the PATH variable from the environment.
 * @envir: The environment variables
 * Return: value of PATH.
 */

char *net_path_from_env(char **envir)
{
	size_t dial = 0, a = 0, length = 5;
	char *line = NULL;

	for (dial = 0; string_compare(envir[dial], "PATH=", 5); dial++)
		;
	if (envir[dial] == NULL)
		return (NULL);

	for (length = 5; envir[dial][a]; a++, length++)
		;
	line = malloc(sizeof(char) * (length + 1));

	if (line == NULL)
		return (NULL);

	for (a = 5, length = 0; envir[dial][a]; a++, length++)
		line[length] = envir[dial][a];

	line[length] = '\0';
	return (line);
}
