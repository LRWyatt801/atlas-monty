#ifndef _MONTY_H
#define _MONTY_H

#include <stdio.h>
#include <stdlib.h>

/*macros*/

#define BUFF_SIZE 1024
#define WHITESPACE " $\n\t\r" /*$ indicates end of line in monty*/

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
		char *intstr;
} globvars_t;
extern globvars_t *globvars;

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

/*file prototypes*/

int filegetline(FILE *fp);
int globvarset(char **tokstr);

/*free prototypes*/

int freematrix(char **arr_name);

/*ops prototypes*/

void (*opfinder(char **op_arr))(stack_t **, unsigned int);
void stk_push(stack_t **top, unsigned int line_number);
void stk_pall(stack_t **top, unsigned int line_number);

/*TODO include all prototypes*/

#endif
