#include "monty.h"

/**
 * free_command - free a full command  array
 *
 * @full_cmd: array of command
 *
 * Return: void
 */
void free_command(char **full_cmd)
{
	int i;

	i = 0;
	while (full_cmd[i] != NULL)
	{
		free(full_cmd[i]);
		i++;
	}
	free(full_cmd);
}

/**
 * get_line_cmds - creates an array of strings from a command
 *
 * @line: line to create an array of strings from
 *
 * Return: array of strings of the full command
 */
char **get_line_cmds(const char *line)
{
	char *line_cpy;
	char *cmd;
	char **full_cmd;
	char *delim = " \n\t";
	int i;

	if (line == NULL)
		return (NULL);
	line_cpy = _strdup(line);
	cmd = strtok(line_cpy, delim);
	if (!cmd || (cmd[0] == 35))
	{
		free(line_cpy);
		return (NULL);
	}
	full_cmd = malloc(sizeof(char *) * 3);
	if (full_cmd == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(line_cpy);
		exit(EXIT_FAILURE);
	}
	for (i = 0; cmd != NULL && i < 2; i++)
	{
		full_cmd[i] = malloc(sizeof(char) * (strlen(cmd) + 1));
		if (full_cmd[i] == NULL)
		{
			fprintf(stderr, "Error: malloc failed\n");
			free(line_cpy);
			free_command(full_cmd);
			free(cmd);
			exit(EXIT_FAILURE);
		}
		strcpy(full_cmd[i], cmd);
		cmd = strtok(NULL, delim);
	}
	free(line_cpy);
	line_cpy = NULL;
	full_cmd[i] = NULL;
	return (full_cmd);
}
