#include "shell.h"

/**
 * string_concat - Concatenate two strings
 * @target: The destination string
 * @origin: The source string to append
 * Return: A pointer to the destination string
 */

char *string_concat(char *target, char *origin)
{
	int t = 0;
	int o = 0;

	while (target[t] != '\0')
	{
		t++;
	}
	while (origin[o] != '\0')
	{
		target[t] = origin[o];
		t++;
		o++;
	}
	target[t] = '\0';
	return (target);
}

/**
 * strin_compare - Compare two strings.
 * @lace1: The first string to compare.
 * @lace2: The second string to compare
 * Return: 0 if strings are equal
 */

int strin_compare(char *lace1, char *lace2)
{
	int x;

	for (x = 0; lace1[x] != '\0' && lace2[x] != '\0';
	x++)
	{
		if (lace1[x] != lace2[x])
			return ((int)lace1[x] - lace2[x]);
	}
	return (0);
}

/**
 * string_length - Calculate the length of a string.
 * @lace: The input string
 * Return: The length of the string
 */

int string_length(char *lace)
{
	int len = 0;

	while (*(lace + len) != '\0')
	{
		len++;
	}

	return (len);
}

/**
 * string_compare - Compare two strings up to n characters.
 * @lace1: The first string to compare
 * @lace2: The second string to compare.
 * @num: The maximum number of characters to compare.
 * Return: 0 if strings are equal up to n characters
 */

size_t string_compare(char *lace1, char *lace2, size_t num)
{
	size_t x, y;

	for (y = 0; lace1[y] != '\0' && y < num; y++)
	{
		x = lace1[y] - lace2[y];

		if (x != 0)
		{
			return (x);
		}
	}
	return (0);
}

/**
 * string_copy - Copy a string to another
 * @target: The destination string
 * @origin: The source string to copy from
 * Return: A pointer to the destination string
 */

char *string_copy(char *target, char *origin)
{
	int x = 0;

	while (*(origin + x) != '\0')
	{
		*(target + x) = *(origin + x);
		++x;
	}
	*(target + x) = *(origin + x);

	return (target);
}
