#include "monty.h"
stack_t *head = NULL;

/**
 * main - entry point
 * @argc: arguments count
 * @argv: list of arguments
 * Return: always 0
 */

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	access_file(argv[1]);
	ffree_nodes();
	return (0);
}

/**
 * define_node - allocating memory to a new node.
 * @n: integer inside the node.
 * Return: a pointer to the node (success). Otherwise NULL.
 */
stack_t *define_node(int n)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
		s_error(4);
	new->next = NULL;
	new->prev = NULL;
	new->n = n;
	return (new);
}

/**
 * ffree_nodes - a function that frees all the nodes in the stack.
 * Return: void.
 */
void ffree_nodes(void)
{
	stack_t *tmp;

	if (head == NULL)
	{
		return;
	}
	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}

/**
 * next_in_queue - a function that adds a node next to the queue.
 * @new_node: a pointer to the new node.
 * @ln: line number of the optcode.
 */
void next_in_queue(stack_t **new_node, __attribute__((unused))unsigned int ln)
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
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *new_node;
	(*new_node)->prev = tmp;
}
