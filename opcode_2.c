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
 * _add - adds the top two elements of the stack
 *
 * @stack: pointer to the top pointer of the stack
 * @line_number: line number of the code
 *
 * Return: void
 */
void _add(stack_t **stack, unsigned int line_number)
{
	int result;
	stack_t *temp = *stack;

	line_number = gvar.ln;

	if (!(*stack) || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		free_command(gvar.argv);
		fclose(gvar.fd);
		exit(EXIT_FAILURE);
	}
	result = (*stack)->n + (*stack)->next->n;
	(*stack)->next->n = result;
	(*stack) = (*stack)->next;
	free(temp);
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

/**
 * _sub - subtracts the top element of the stack
 * from the second top element of the stack
 *
 * @stack: pointer to the top pointer of the stack
 * @line_number: line number of the code
 *
 * Return: void
 */
void _sub(stack_t **stack, unsigned int line_number)
{
	int result;
	stack_t *temp = *stack;

	line_number = gvar.ln;

	if (!(*stack) || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		free_command(gvar.argv);
		fclose(gvar.fd);
		exit(EXIT_FAILURE);
	}
	result = (*stack)->next->n - (*stack)->n;
	(*stack)->next->n = result;
	(*stack) = (*stack)->next;
	free(temp);
}

/**
 * _divide - divides the second top element of the stack
 * by the top element of the stack
 *
 * @stack: pointer to the top pointer of the stack
 * @line_number: line number of the code
 *
 * Return: void
 */
void _divide(stack_t **stack, unsigned int line_number)
{
	int result;
	stack_t *temp = *stack;

	line_number = gvar.ln;

	if (!(*stack) || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		free_command(gvar.argv);
		fclose(gvar.fd);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free_command(gvar.argv);
		fclose(gvar.fd);
		exit(EXIT_FAILURE);
	}
	result = (*stack)->next->n / (*stack)->n;
	(*stack)->next->n = result;
	(*stack) = (*stack)->next;
	free(temp);
}
