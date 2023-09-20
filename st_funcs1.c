#include "monty.h"

/**
 * nodes_switch - a function that switches the top two nodes of the stack.
 * @st: a pointer to a pointer pointing to the top node of the stack.
 * @l_num: integer representing the line number of of the optcode.
 */
void nodes_switch(stack_t **st, unsigned int l_num)
{
	stack_t *tmp;

	if (st == NULL || *st == NULL || (*st)->next == NULL)
	{
		m_error(8, l_num, "swap");
	}
	tmp = (*st)->next;
	(*st)->next = tmp->next;
	if (tmp->next != NULL)
	{
		tmp->next->prev = *st;
	}
	tmp->next = *st;
	(*st)->prev = tmp;
	tmp->prev = NULL;
	*st = tmp;
}

/**
 * nodes_addition - a function that adds the top two nodes of the stack.
 * @st: a pointer to a pointer pointing to the top node of the stack.
 * @l_num: integer representing the line number of of the optcode.
 */
void nodes_addition(stack_t **st, unsigned int l_num)
{
	int sum;

	if (st == NULL || *st == NULL || (*st)->next == NULL)
	{
		m_error(8, l_num, "add");
	}
	(*st) = (*st)->next;
	sum = (*st)->n + (*st)->prev->n;
	(*st)->n = sum;
	free((*st)->prev);
	(*st)->prev = NULL;
}

/**
 * nop - a function that does nothing.
 * @st: a pointer to a pointer pointing to the top node of the stack.
 * @l_num: integer representing the line number of of the optcode.
 */
void nop(stack_t **st, unsigned int l_num)
{
	(void)st;
	(void)l_num;
}

/**
 * nodes_subtract - a function that subtracts the top two nodes of the stack.
 * @st: a pointer to a pointer pointing to the top node of the stack.
 * @l_num: integer representing the line number of of the optcode.
 */
void nodes_subtract(stack_t **st, unsigned int l_num)
{
	int sub;

	if (st == NULL || *st == NULL || (*st)->next == NULL)
	{
		m_error(8, l_num, "sub");
	}
	(*st) = (*st)->next;
	sub = (*st)->n - (*st)->prev->n;
	(*st)->n = sub;
	free((*st)->prev);
	(*st)->prev = NULL;
}

/**
 * nodes_div - a function that divides the top two nodes of the stack.
 * @st: a pointer to a pointer pointing to the top node of the stack.
 * @l_num: integer representing the line number of of the optcode.
 */
void nodes_div(stack_t **st, unsigned int l_num)
{
	int div;

	if (st == NULL || *st == NULL || (*st)->next == NULL)
	{
		m_error(8, l_num, "div");
	}
	if ((*st)->n == 0)
		m_error(9, l_num);
	(*st) = (*st)->next;
	div = (*st)->n / (*st)->prev->n;
	(*st)->n = div;
	free((*st)->prev);
	(*st)->prev = NULL;
}
