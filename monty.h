#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

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

extern stack_t *head;
typedef void (*op_func)(stack_t **, unsigned int);

/*file operations*/
void open_file_1(char *file_name);
int parse_line_2(char *buffer, int line_number, int format);
void read_file_n(FILE *);
int len_chars(FILE *);
void find_func_m(char *, char *, int, int);

/*Stack operations*/
stack_t *create_node(int n);
void free_nodes(void);
void print_stack(stack_t **, unsigned int);
void add_to_stack(stack_t **, unsigned int);
void add_to_queue(stack_t **, unsigned int);

void call_fun(op_func, char *, char *, int, int);

void to_print_top(stack_t **, unsigned int);
void popout_top(stack_t **, unsigned int);
void nope(stack_t **, unsigned int);
void swap_to_nodes(stack_t **, unsigned int);

/*Math operations with nodes*/
void add_to_nodes(stack_t **, unsigned int);
void subbe_nodes(stack_t **, unsigned int);
void divide_nodes(stack_t **, unsigned int);
void the_mul_nodes(stack_t **, unsigned int);
void the_mod_nodes(stack_t **, unsigned int);

/*String operations*/
void to_print_char(stack_t **, unsigned int);
void to_print_str(stack_t **, unsigned int);
void the_rotl(stack_t **, unsigned int);

/*Error hanlding*/
void err_er(int error_code, ...);
void more_err_q(int error_code, ...);
void string_err_w(int error_code, ...);
void the_rotr(stack_t **, unsigned int);

#endif
