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
	int n;
	(void)line_number;

	n = atoi(globvars->intstr);

	newTop = malloc(sizeof(stack_t));
	if (newTop == NULL)
		{
			fprintf(stderr, "Error: malloc failed\n");
			exit(EXIT_FAILURE);
		}

	newTop->n = n;
	newTop->prev = NULL;
	newTop->next = *top;
	if (*top != NULL)
		(*top)->prev = newTop;
	*top = newTop;
}