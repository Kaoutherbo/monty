#include "monty.h"

/**
 * _strdup - copies a string
 *
 * @input: string to be copied
 *
 * Return: copy of the string
 */
char *_strdup(const char *input)
{
	char *copy;
	int i;

	copy = malloc(sizeof(char) * (strlen(input) + 1));
	if (copy == NULL)
	{
		perror("malloc");
		exit(1);
	}

	for (i = 0; input[i] != '\0'; i++)
		copy[i] = input[i];

	copy[i] = '\0';
	return (copy);
}
