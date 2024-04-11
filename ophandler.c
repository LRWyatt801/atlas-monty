#include "monty.h"
#include <string.h>

/**
 * oprunner - runs the operation
 * Return: n/a
*/

void oprunner ()
{
	void (*func)(stack_t **, unsigned int);

	func = getop();
	printf("1\n");
	func(&globvars.top, globvars.line_number);
}

/**
 * opfinder - finds the operation/function to run
 * @op: function to find
 * 
 * Return: function pointer
*/

void (*getop())(stack_t **, unsigned int)
{
	instruction_t ops[] = {
		{"push", stk_push},
		{"pall", stk_pall},
		{NULL, NULL}
	};
	int i = 0;

	while (ops[i].opcode != NULL)
	{
		if (strcmp(ops[i].opcode, globvars.optok) == 0)
			return (ops[i].f);
		i++;
	}
	errorhandler(3);
	return (NULL);
}
