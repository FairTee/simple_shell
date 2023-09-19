#include "shell.h"

/**
 * tokenize_string - Tokenize a string based on a specified delimeters
 * @in_len: string to tokenize
 * @del: delimeter character
 * Return: next token
 */
char *tokenize_string(char *in_len, const char *del)
{
	static char *end;

	if (in_len)
		end = in_len;
	else if (!end)
		return (0);
	in_len = end + point_string(end, del);
	end = in_len + comp_string(in_len, del);
	if (end == in_len)
		return (end = 0);
	end = *end ? *end = 0, end + 1 : 0;
	return (in_len);
}
/**
 * comp_string - comapares length of string
 * @lace1: string to check
 * @lace2: string useful to comapare
 * Return: length of segment
 */
size_t comp_string(const char *lace1, const char *lace2)
{
	size_t fill = 0;

	while (*lace1)
	{
		if (charac_string(lace2, *lace1))
			return (fill);
		lace1++, fill++;
	}
	return (fill);
}

/**
 * point_string - computes the length strings
 * @lace1: string to compute the length
 * @lace2: string delimit
 * Return: 0
 */
size_t point_string(const char *lace1, const char *lace2)
{
	size_t fill = 0;

	while (*lace1 && charac_string(lace2, *lace1++))
		fill++;
	return (fill);
}

/**
 * charac_string - finds the first occurence of w in string pointed by l
 * @l: the strings
 * @w: the characters
 * Return: ponter
 */
char *charac_string(const char *l, int w)
{
	while (*l != (char)w)
		if (!*l++)
			return (0);
	return ((char *)l);
}
