#ifndef HEADER_H
#define HEADER_H

#define _GNU_SOURCE
#include <stdlib.h>
#include <stdio.h>

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

int verify_allocation(void *tmp);
int verify_stream(FILE *stream, char *file);
int verify_argc(int argc);
int verify_opc(void (*f)(stack_t **, unsigned int), char *op, int l);
int verify_int(int arg, int l, char *s);

char** identify_opcode(char **tmp, char *line);
int count(char *line, int *i);
void (*get_opcode(char **s))(stack_t **, unsigned int);

int _strlen(char *str);
int _strcmp(char *s1, char *s2);

void push(stack_t **stack, unsigned int line);
void pall(stack_t **stack, __attribute__((unused)) unsigned int line);
void pint(stack_t **stack, unsigned int line);
void pop(stack_t **stack, unsigned int line);
void empty(__attribute__((unused))stack_t **stack, 
		__attribute__((unused))unsigned int line);

/*extern stack_t *stack;*/

#endif
