#include "monty.h"

/**
 * select_opcode - selects the right function to execute
 *
 * @code: the function's opcode
 *
 * Return: pointer to the selected function
 */
void (*select_opcode(char *code))(stack_t **stack, unsigned int line_number)
{
	int i;
	instruction_t stack_functions[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop},
		{"sub", _sub},
		{"div", _divide},
		{"mul", _mul},
		{"mod", _mod},
		{"pchar", _pchar},
		{"pstr", _pstr},
		{"rotl", _rotl},
		{"rotr", _rotr},
		{NULL, NULL}};

	for (i = 0; stack_functions[i].opcode; i++)
	{
		if (strcmp(stack_functions[i].opcode, code) == 0)
			break;
	}

	return (stack_functions[i].f);
}
