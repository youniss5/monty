#include "monty.h"

/**
 * p_char - a function that Prints (ASCII value).
 * @st: a pointer to the pointer that points to the top node of stack.
 * @l_num: Int (the line number of the operation code)
 */
void p_char(stack_t **st, unsigned int l_num)
{
	int ascii;

	if (st == NULL || *st == NULL)
	{
		str_error(11, l_num);
	}
	ascii = (*st)->n;
	if (ascii < 0 || ascii > 127)
		str_error(10, l_num);
	printf("%c\n", ascii);
}

/**
 * p_str - a function that Prints a string.
 * @st: a pointer to the pointer that points to the top node of stack.
 * @ln: Int (the line number of the operation code)
 */
void p_str(stack_t **st, __attribute__((unused))unsigned int ln)
{
	int ascii;
	stack_t *tm;

	if (st == NULL || *st == NULL)
	{
		printf("\n");
		return;
	}

	tm = *st;
	while (tm != NULL)
	{
		ascii = tm->n;
		if (ascii <= 0 || ascii > 127)
			break;
		printf("%c", ascii);
		tm = tm->next;
	}
	printf("\n");
}

/**
 * rotatel - a function that rotates the first node of stack to the end.
 * @st: a pointer to the pointer that points to the top node of stack.
 * @ln: Int (the line number of the operation code)
 */
void rotatel(stack_t **st, __attribute__((unused))unsigned int ln)
{
	stack_t *tm;

	if (st == NULL || *st == NULL || (*st)->next == NULL)
		return;

	tm = *st;
	while (tm->next != NULL)
		tm = tm->next;

	tm->next = *st;
	(*st)->prev = tm;
	*st = (*st)->next;
	(*st)->prev->next = NULL;
	(*st)->prev = NULL;
}

/**
 * rotate2 - a function that rotates last node of stack to the top.
 * @st: a pointer to the pointer that points to the top node of stack.
 * @ln: Int (the line number of the operation code).
 */
void rotate2(stack_t **st, __attribute__((unused))unsigned int ln)
{
	stack_t *tm;

	if (st == NULL || *st == NULL || (*st)->next == NULL)
		return;

	tm = *st;

	while (tm->next != NULL)
		tm = tm->next;

	tm->next = *st;
	tm->prev->next = NULL;
	tm->prev = NULL;
	(*st)->prev = tm;
	(*st) = tm;
}
