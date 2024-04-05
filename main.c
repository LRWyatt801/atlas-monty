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
	int count = 1; /*line count starts at 1 for 1st line*/
	int running = 1; /*forced loop for running*/
	char *montyfile; /*file for montybyte commands*/
	
	if (argc != 2) /*check for 2 args only*/
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	montyfile = filereader(argv[1]); /*reads file to montyfile*/
	while(running)
	{
		filegetline(montyfile);/*get line of file*/
		opfinder();/*finds cmd to execute*/
	}
}