#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * main - entry point for program "monty"
 * @argc: number of argv
 * @argv: argument input, in this case a file
 *
 * Return: EXIT_SUCCESS on a success, or EXIT_FAILURE for any error
*/

int main(int argc, char **argv)
{
	stack_t *montystk = NULL;
	int running = 1; /*forced loop for running*/
	FILE *montyfile; /*file for montybyte commands*/
	char **optok = NULL;
	
	if (argc != 2) /*check for 2 args only*/
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	montyfile = fopen(argv[1], "r");
	if (montyfile == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit (EXIT_FAILURE);
	}
	while(running)
	{
		optok = filegetline(montyfile);/*get line of file and tokens*/
		opfinder(optok);/*finds cmd to execute*/
	}
}