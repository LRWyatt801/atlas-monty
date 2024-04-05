#include "monty.h"

/**
 * freematrix - frees a matrix
 * @array: array to be freed
 *
 * Return: 0 on success
*/

int freematrix(char **arr_name)
{
	int i;

	for (i = 0; arr_name[i] != NULL; i++)
	{
		free(arr_name[i]);
	}
	free(arr_name);
	return (0);
}