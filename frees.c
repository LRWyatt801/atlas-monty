#include "monty.h"

/**
 * freestk - frees the stack
 * @top: top of stack
 * Return: n/a
*/

void freestk(stack_t *top)
{
	stack_t *tmp;

	while (top != NULL)
	{
		tmp = top;
		top = top->next;
		free(tmp);
	}
}