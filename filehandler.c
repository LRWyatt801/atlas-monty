#include "monty.h"
#include <string.h>
#include <ctype.h>

/**
 * filehandler - handles the monty
 * @filename: name of the file
 * Return: n/a
*/

void filehandler(char *filename)
{
	FILE *fp = fopen(filename, "r");

	globvars.filename = filename;
	if (filename == NULL || fp == NULL)
		errorhandler(2);

	readfile(fp);
	fclose(fp);
}

/**
 * readfile - reads the file
 * @filep: pointer to file
 * Return: n/a
*/

void readfile(FILE *filep)
{
	char *buff = NULL;
	size_t size = BUFF_SIZE;

	for (globvars.line_number = 1; getline(&buff, &size, filep) != -1; globvars.line_number++)
	{
		parseline(buff);
	}
	free(buff);
}

/**
 * parseline - breaks the line into tokens
 * @buffer: line from buffer
 * Return: n/a
*/

void parseline(char *buffer)
{
	char *val, *optok;
	int flag, i;

	if (buffer == NULL)
		errorhandler(4);

	optok= strtok(buffer, WHITESPACE);
	globvars.optok = strdup(optok);
	if (globvars.optok == NULL)
		errorhandler(4);
	val = strtok(NULL, WHITESPACE);

	if (strcmp(globvars.optok, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			flag = -1;
		}
		if (val == NULL)
			errorhandler(5);
		for (i = 0; val[i] != '\0'; i++)
		{
			if (isdigit(val[i]) == 0)
				errorhandler(5);
		}
		globvars.n = (atoi(val) * flag);
	}
}
