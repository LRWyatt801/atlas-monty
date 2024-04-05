#ifndef _MONTY_H
#define _MONTY_H

#include <stdio.h>
#include <stdlib.h>

/*macros*/

#define BUFF_SIZE 1024
#define WHITESPACE " \n\t\r"

/*GLOBAL VARIABLES (make struct if needed)*/

int line_count = 1;

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

char *filegetline(char *filename);

/*free prototypes*/

int freematrix(char **arr_name);

/*ops prototypes*/

stack_t *stk_push(stack_t **top);
size_t stk_pall(stack_t *top);

/*TODO include all prototypes*/

#endif
