#include "monty.h"

/**
 * errorhandler - handles all errors
 * @errnum: error number to handle
 * Return: n/a
*/

void errorhandler(const int errnum)
{
	switch (errnum)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n", globvars.filename);
			break;
		case 3:
			fprintf(stderr, "L%d: unknown instruction %s\n", globvars.line_number, globvars.optok);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push interger\n", globvars.line_number);
			break;
		default:
			break;
		
		freestk(globvars.top);
		exit(EXIT_FAILURE);
	}
}