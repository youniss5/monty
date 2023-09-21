#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

/**
 * struct stack_s - stack or queue represented in doubly linked list.
 * @n: an int.
 * @prev: points to the previous element of the stack (or queue).
 * @next: points to the next element of the stack (or queue).
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO.
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - optcode and its function.
 * @optcode: the optcode.
 * @f: function to handle the optcode.
 * Description: optcode and its function.
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *optcode;
        void (*f)(stack_t **st, unsigned int l_num);
} instruction_t;

extern stack_t *head;
typedef void (*op_func)(stack_t **, unsigned int);

/**main.c*/
stack_t *define_node(int n);
void ffree_nodes(void);
void next_in_queue(stack_t **new_node, unsigned int ln);

/**file_ops.c*/
void access_file(char *file_name);
void file_read(FILE *);
int parse_ln(char *buff, int l_num, int format);
void stack_finc(char *optcode, char *val, int ln, int format);
void call_f(op_func func, char *oper, char *val, int ln, int format);

/**st_funcs.c*/
void st_node_add(stack_t **new_node, unsigned int ln);
void st_print(stack_t **st, unsigned int l_num);
void st_pop(stack_t **st, unsigned int l_num);
void top_print(stack_t **st, unsigned int l_num);

/**st_funcs1.c*/
void nodes_switch(stack_t **st, unsigned int l_num);
void nodes_addition(stack_t **st, unsigned int l_num);
void nop(stack_t **st, unsigned int l_num);
void nodes_subtract(stack_t **st, unsigned int l_num);
void nodes_div(stack_t **st, unsigned int l_num);

/**st_funcs2.c*/
void nodes_product(stack_t **st, unsigned int l_num);
void nodes_remainder(stack_t **st, unsigned int l_num);

void p_char(stack_t **, unsigned int);
void p_str(stack_t **, unsigned int);
void rotatel(stack_t **, unsigned int);

void s_error(int err_c, ...);
void m_error(int err_c, ...);
void str_error(int err_c, ...);
void rotate2(stack_t **, unsigned int);

#endif
