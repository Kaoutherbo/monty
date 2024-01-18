#include "monty.h"

global_t gvar;
/**
 * main - monty interpreter
 *
 * @argc: number of arguments
 * @argv: passed arguments
 *
 * Return: 0 if success, 1 otherwise
 */
int main(int argc, char *argv[])
{
	void (*f)(stack_t **stack, unsigned int line_number) = NULL;
	char line[1000];

	gvar.argv = NULL;
	gvar.ln = 0;
	gvar.top = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	gvar.fd = fopen(argv[1], "r");
	if (gvar.fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((fgets(line, 1000, gvar.fd)) != NULL)
	{
		gvar.ln++;
		gvar.argv = get_line_commands(line);
		if (!gvar.argv)
			continue;
		f = select_opcode(gvar.argv[0]);
		if (!f)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", gvar.ln, gvar.argv[0]);
			fclose(gvar.fd);
			free_dlistint(gvar.top);
			free_full_command(gvar.argv);
			exit(EXIT_FAILURE);
		}
		f(&gvar.top, gvar.ln);
		free_full_command(gvar.argv);
	}
	fclose(gvar.fd);
	free_dlistint(gvar.top);
	return (0);
}
