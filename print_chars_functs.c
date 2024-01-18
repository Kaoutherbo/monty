#include "monty.h"


/**
 * _pchar - prints the char at the top of the stack, followed by a new line
 *
 * @stack: pointer to the top pointer of the stack
 * @line_number: line number of the code
 *
 * Return: void
 */
void _pchar(stack_t **stack, unsigned int line_number)
{
	line_number = gvar.ln;

	if (!(*stack))
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		free_command(gvar.argv);
		fclose(gvar.fd);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n >= 0 && (*stack)->n <= 127)
		printf("%c\n", (*stack)->n);
	else
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		free_command(gvar.argv);
		fclose(gvar.fd);
		exit(EXIT_FAILURE);
	}
}

/**
 * _pstr - prints the string starting at the top of the stack,
 * followed by a new line
 *
 * @stack: pointer to the top pointer of the stack
 * @line_number: line number of the code
 *
 * Return: void
 */
void _pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	(void)line_number;

	while (temp != NULL)
	{
		if (temp->n > 0 && temp->n <= 127)
		{
			printf("%c", temp->n);
			temp = temp->next;
		}
		else
			break;
	}
	printf("\n");
}
