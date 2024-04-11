#include "monty.h"

/**
 * stk_push - pushes a function on the stack
 * @top: head of my stack
 *
 * Return: pointer to top of stack
*/

void stk_push(stack_t **top, unsigned int line_number)
{
	stack_t *newTop = NULL;
	(void)line_number;

	printf("8\n");

	newTop = malloc(sizeof(stack_t));
	if (newTop == NULL)
		errorhandler(4);

	newTop->n = globvars.n;
	newTop->prev = NULL;
	newTop->next = *top;
	if (*top != NULL)
		(*top)->prev = newTop;
	*top = newTop;
}