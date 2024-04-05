#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * filegetline - gets a line from file and tokenizes it
 * @filename: file that has been read
 *
 * Return: returns line
*/

char *filegetline(char *filename)
{
	char **newarr = NULL;
	char *tok, *buff = NULL;
	size_t size = BUFF_SIZE;
	int i;

	newarr = malloc(sizeof(char *));
	buff = malloc(size);
	if (newarr == NULL || buff == NULL)
	{
		freematrix(newarr);
		free(buff);
		exit(EXIT_FAILURE);
	}
	if (getline(&buff, &size, filename) < 0) /*get file line input*/
	{
		free(newarr);
		free(buff);
		exit(EXIT_FAILURE);
	}
	/*get tokens*/
	tok = strtok(buff, WHITESPACE);
	newarr[0] = strdup(tok);
	for (i = 1; tok != NULL; i++)
	{
		tok = strtok(NULL, WHITESPACE);
		if (tok != NULL)
		{
			newarr[i] = strdup(tok);
			if (newarr[0] == NULL || newarr[i] == NULL)
			{
				freematrix(newarr);
				free(buff);
				exit(EXIT_FAILURE);
			}
		}
		else
			newarr[i] = NULL;
	}
	free(buff);
	free(tok);
	return (newarr);
}
