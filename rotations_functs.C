#include "monty.h"


/**
 * _rotl - rotates the stack to the top
 *
 * @stack: pointer to the top pointer of the stack
 * @line_number: line number of the code
 *
 * Return: void
 */
void _rotl(stack_t **stack, unsigned int line_number)
{
        stack_t *temp = *stack;

        (void)line_number;

        if (*stack && (*stack)->next != NULL)
        {
                while (temp->next != NULL)
                        temp = temp->next;
                temp->next = *stack;
                (*stack)->prev = temp;
                (*stack) = (*stack)->next;
                (*stack)->prev = NULL;
                temp->next->next = NULL;
        }
}

/**
 * _rotr - rotates the stack to the bottom
 *
 * @stack: pointer to the top pointer of the stack
 * @line_number: line number of the code
 *
 * Return: void
 */
void _rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	(void)line_number;

	if (*stack && (*stack)->next != NULL)
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->prev->next = NULL;
		temp->prev = NULL;
		temp->next = *stack;
		(*stack)->prev = temp;
		*stack = temp;
	}
}
