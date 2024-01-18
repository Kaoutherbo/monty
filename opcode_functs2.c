#include "monty.h"

/**
 * _swap - swaps the top two elements of the stack
 *
 * @stack: pointer to the top pointer of the stack
 * @line_number: line number of the code
 *
 * Return: void
 */
void _swap(stack_t **stack, unsigned int line_number)
{
	int next_num;

	line_number = gvar.ln;

	if (!(*stack) || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		free_command(gvar.argv);
		fclose(gvar.fd);
		exit(EXIT_FAILURE);
	}
	next_num = (*stack)->next->n;
	(*stack)->next->n = (*stack)->n;
	(*stack)->n = next_num;
}


/**
 * _nop - doesn't do anything
 *
 * @stack: pointer to the top pointer of the stack
 * @line_number: line number of the code
 *
 * Return: void
 */
void _nop(stack_t **stack, unsigned int line_number)
{
	(void)**stack;
	(void)line_number;
}
