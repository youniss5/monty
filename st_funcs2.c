#include "monty.h"

/**
 * nodes_product - inserts the multiplication of two top elements of the stack
 * @st: a pointer to the pointer that points to the top node of stack.
 * @l_num: Int (the line number of the operation code)
 */
void nodes_product(stack_t **st, unsigned int l_num)
{
	int result;

	if (st == NULL || *st == NULL || (*st)->next == NULL)
		m_error(8, l_num, "mul");

	(*st) = (*st)->next;
	result = (*st)->n * (*st)->prev->n;
	(*st)->n = result;
	free((*st)->prev);
	(*st)->prev = NULL;
}


/**
 * nodes_remainder - inserts the moduls of the top two elements of stack.
 * @st: a pointer to the pointer that points to the top node of stack
 * @l_num: Int (the line number of the operation code).
 */
void nodes_remainder(stack_t **st, unsigned int l_num)
{
	int result;

	if (st == NULL || *st == NULL || (*st)->next == NULL)

		m_error(8, l_num, "mod");


	if ((*st)->n == 0)
		m_error(9, l_num);
	(*st) = (*st)->next;
	result = (*st)->n % (*st)->prev->n;
	(*st)->n = result;
	free((*st)->prev);
	(*st)->prev = NULL;
}
