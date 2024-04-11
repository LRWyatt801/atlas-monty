#include "monty.h"

globvars_t globvars;

/**
 * main - entry point for program "monty"
 * @argc: number of argv
 * @argv: argument input, in this case a file
 *
 * Return: EXIT_SUCCESS on a success, or EXIT_FAILURE for any error
*/

int main(int argc, char **argv)
{
	if (argc != 2)
		errorhandler(1);
	filehandler(argv[1]);/*handles each line of file*/
	printf("%d\n", globvars.n);
	oprunner();
	freestk(globvars.top);
}
