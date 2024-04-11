#ifndef _MONTY_H
#define _MONTY_H

#include <stdio.h>
#include <stdlib.h>

/*macros*/

#define BUFF_SIZE 1024
#define WHITESPACE " $\n\t\r" /*$ indicates end of line in monty*/

/*structs*/

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/*GLOBAL VARIABLE*/

/**
 * struct GLOBVARS - structure of global variables
 * @line_number: line number being executed in Montybytes file
 * @optok: token for operation from Montybytes file
 * @strn: int from Montybytes file
*/

typedef struct GLOBVARS_s
{
		unsigned int line_number;
		char *optok;
		int n;
		stack_t *top;
		char *filename;
} globvars_t;
extern globvars_t globvars;

/*errors.c prototypes*/

void errorhandler(const int errnum);

/*filehandler.c prototypes*/

void filehandler(char *filename);
void readfile(FILE *filep);
void parseline(char *buffer);

/*frees.c prototypes*/

void freestk(stack_t *top);

/*ophandler.c prototypes*/

void oprunner();
void (*getop())(stack_t **, unsigned int);


/*stackfunctions. prototypes*/

void stk_push(stack_t **top, unsigned int line_number);

/*printfunctions.c prototypes*/

void stk_pall(stack_t **top, unsigned int line_number);

/*TODO include all prototypes*/

#endif
