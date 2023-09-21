#include "monty.h"

/**
 * st_node_add - adds a new node to the stack.
 * @new_node: a pointer to the new node.
 * @l_num: integer representing the line number of of the optcode.
 */
void st_node_add(stack_t **new_node, __attribute__((unused))unsigned int l_num)
{
	stack_t *tmp;

	if (new_node == NULL || *new_node == NULL)
	{
		exit(EXIT_FAILURE);
	}
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	tmp = head;
	head = *new_node;
	head->next = tmp;
	tmp->prev = head;
}


/**
 * st_print - a function that prints the stack integers.
 * @st:a pointer to a pointer pointing to the top node of the stack.
 * @l_num: line number of the optcode.
 */
void st_print(stack_t **st, unsigned int l_num)
{
	stack_t *tmp;

	(void) l_num;
	if (st == NULL)
		exit(EXIT_FAILURE);
	tmp = *st;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * st_pop - removes the top node of the stack.
 * @st: a pointer to a pointer pointing to the top node of the stack.
 * @l_num: integer representing the line number of of the optcode.
 */
void st_pop(stack_t **st, unsigned int l_num)
{
	stack_t *tmp;

	if (st == NULL || *st == NULL)
	{
		m_error(7, l_num);
	}
	tmp = *st;
	*st = tmp->next;
	if (*st != NULL)
	{
		(*st)->prev = NULL;
	}
	free(tmp);
}

/**
 * top_print - a function that prints the top node of the stack.
 * @st: a pointer to a pointer pointing to the top node of the stack.
 * @l_num: Integer representing the line number of of the optcode.
 */
void top_print(stack_t **st, unsigned int l_num)
{
	if (st == NULL || *st == NULL)
		m_error(6, l_num);
	printf("%d\n", (*st)->n);
}
