#include "monty.h"
#include <string.h>

/**
 * filegetline - gets a line from file and tokenizes it
 * @filename: file that has been read
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
*/

int filegetline(FILE *fp)
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
	if (getline(&buff, &size, fp) < 0) /*get file line input*/
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
	globvarset(newarr);
	free(buff);
	free(tok);
	freematrix(newarr);
	return (EXIT_SUCCESS);
}

/**
 * globvarset - sets global variables strn and optok
 * @tokstr: tokenized matrix
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
*/

int globvarset(char **tokstr)
{
	globvars = malloc(sizeof(globvars_t));
	globvars->optok = strdup(tokstr[0]);
	globvars->intstr = strdup(tokstr[1]);
	if (globvars->optok == NULL || globvars->intstr == NULL)
	{
		free(globvars->optok);
		free(globvars->intstr);
		free(globvars);
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
