#include "shell.h"

/**
 * tokenize_input - Tokenize user input into an array of strings.
 * @input: The input string to tokenize
 * Return: pointer to the array of token strings
 */

char **tokenize_input(char *input)
{
	char **cmd_tokens = NULL;
	char *souv = NULL;
	size_t souv_count = 0;
	int dim = 0;

	if (input == NULL)
		return (NULL);

	for (souv_count = 0; input[souv_count];
	souv_count++)
	{
		if (input[souv_count] == ' ')
			dim++;
	}
	if ((dim + 1) == string_length(input))
		return (NULL);
	cmd_tokens = malloc(sizeof(char *) * (dim + 2));
	if (cmd_tokens == NULL)
		return (NULL);

	souv = tokenize_string(input, " \n\t\r");
	for (souv_count = 0; souv != NULL;
	souv_count++)
	{
		cmd_tokens[souv_count] = souv;
		souv = tokenize_string(NULL, " \n\t\r");
	}
	cmd_tokens[souv_count] = NULL;
	return (cmd_tokens);
}
