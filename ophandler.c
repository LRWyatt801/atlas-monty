#include "monty.h"
#include <string.h>

/**
 * opfinder - finds the operation/function to run
 * @op: function to find
 * 
 * Return: function pointer
*/

void (*opfinder(char **op_arr))(stack_t **, unsigned int)
{
	instruction_t ops[] = {
		{"push", stk_push},
		{"pall", stk_pall},
		/*{"pint", stk_pint},
		{"pop", stk_pop},
		{"swap", stk_swap},
		{"add", stk_add},
		{"nop", stk_nop},*/
		{NULL, NULL}
	};
	int i;

	while (ops[i].opcode != NULL)
	{
		if (strcmp(ops[i].opcode, op_arr[0]) == 0)
			return (ops[i].f);
		i++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", globvars->line_number, op_arr[0]);
	exit(EXIT_FAILURE);
}