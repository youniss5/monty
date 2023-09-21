#include "monty.h"

/**
 * nodes_product - insert top two elements of stack.
 * @st: Pointer to the pointer that points to the top node of stack
 * @l_num: Int (the line number of the operation code)
 */
void nodes_product(stack_t **st, unsigned int l_num)
{
	int sum;

	if (st == NULL || *st == NULL || (*st)->next == NULL)
		m_error(8, l_num, "mul");

	(*st) = (*st)->next;
	sum = (*st)->n * (*st)->prev->n;
	(*st)->n = sum;
	free((*st)->prev);
	(*st)->prev = NULL;
}


/**
 * nodes_remainder - insert the top two elements of stack.
 * @st: Pointer to the pointer that points to the top node of stack
 * @l_num: Int (the line number of the operation code).
 */
void nodes_remainder(stack_t **st, unsigned int l_num)
{
	int sum;

	if (st == NULL || *st == NULL || (*st)->next == NULL)

		m_error(8, l_num, "mod");


	if ((*st)->n == 0)
		m_error(9, l_num);
	(*st) = (*st)->next;
	sum = (*st)->n % (*st)->prev->n;
	(*st)->n = sum;
	free((*st)->prev);
	(*st)->prev = NULL;
}
