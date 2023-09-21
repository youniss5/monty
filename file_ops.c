#include "monty.h"

/**
 * access_file - accessing a file.
 * @file_name: the path of file name.
 * Return: void.
 */

void access_file(char *file_name)
{
	FILE *fd = fopen(file_name, "r");

	if (file_name == NULL || fd == NULL)
	{
		s_error(2, file_name);
	}
	file_read(fd);
	fclose(fd);
}


/**
 * file_read - a function that reads a file.
 * @fd: pointer to a file descriptor.
 * Return: void.
 */

void file_read(FILE *fd)
{
	int l_num, format = 0;
	size_t len = 0;
	char *buff = NULL;

	for (l_num = 1; getline(&buff, &len, fd) != -1; l_num++)
	{
		format = parse_ln(buff, l_num, format);
	}
	free(buff);
}


/**
 * parse_ln - breaks each line into tokens to determine which func to call.
 * @buff: a line read from the file.
 * @l_num: line number.
 * @format: format indicator, If 0 Nodes will be inserted as a stack,
 * if 1 nodes will be inserted as a queue.
 * Return: Returns 0 if the opcode == stack. 1 if queue.
 */

int parse_ln(char *buff, int l_num, int format)
{
	char *optcode, *val;
	const char *delim = "\n ";

	if (buff == NULL)
		s_error(4);

	optcode = strtok(buff, delim);
	if (optcode == NULL)
		return (format);
	val = strtok(NULL, delim);

	if (strcmp(optcode, "stack") == 0)
		return (0);
	if (strcmp(optcode, "queue") == 0)
		return (1);

	stack_func(optcode, val, l_num, format);
	return (format);
}

/**
 * stack_func - links the optcode to its appropriate function.
 * @optcode: stack function ref.
 * @val: optcode argument.
 * @format: format indicator, If 0 Nodes will be inserted as a stack,
 * if 1 nodes will be inserted as a queue.
 * @ln: line number.
 * Return: void.
 */
void stack_func(char *optcode, char *val, int ln, int format)
{
	int x;
	int flag;

	instruction_t func_list[] = {
		{"push", st_node_add},
		{"pall", st_print},
		{"pint", top_print},
		{"pop", st_pop},
		{"nop", nop},
		{"swap", nodes_switch},
		{"add", nodes_addition},
		{"sub", nodes_subtract},
		{"div", nodes_div},
		{"mul", nodes_product},
		{"mod", nodes_remainder},
		{"pchar", p_char},
		{"pstr", p_str},
		{"rotl", rotate1},
		{"rotr", rotate2},
		{NULL, NULL}
	};

	if (optcode[0] == '#')
		return;

	for (flag = 1, x = 0; func_list[x].optcode != NULL; x++)
	{
		if (strcmp(optcode, func_list[x].optcode) == 0)
		{
			call_f(func_list[x].f, optcode, val, ln, format);
			flag = 0;
		}
	}
	if (flag == 1)
		s_error(3, ln, optcode);
}


/**
 * call_f - Calls the required function.
 * @func: Pointer to the function that is about to be called.
 * @oper: optcode represented as a string.
 * @val: numerical value represented as string.
 * @ln: line numeber of the instruction.
 * @format: format indicator, If 0 Nodes will be inserted as a stack,
 * if 1 nodes will be inserted as a queue.
 */
void call_f(op_func func, char *oper, char *val, int ln, int format)
{
	stack_t *node;
	int flag;
	int x;

	flag = 1;
	if (strcmp(oper, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			flag = -1;
		}
		if (val == NULL)
			s_error(5, ln);
		for (x = 0; val[x] != '\0'; x++)
		{
			if (isdigit(val[x]) == 0)
				s_error(5, ln);
		}
		node = define_node(atoi(val) * flag);
		if (format == 0)
			func(&node, ln);
		if (format == 1)
			next_in_queue(&node, ln);
	}
	else
		func(&head, ln);
}
