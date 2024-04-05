#include "monty.h"

/**
 * stk_pall - prints all nodes in stack
 * @top: top of stack
 * @line_number: line being executed
 *
 * Return: n/a
*/

void stk_pall(stack_t **top, unsigned int line_number)
{
	stack_t *tmp;
	tmp = *top;
	(void)line_number;
	
	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}