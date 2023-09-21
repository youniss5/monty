#include "monty.h"

/**
 * s_error - show the suitable error message depending on error case
 * @err_c: error codes are :
 * case(1) => user gives no files or more than one file .
 * case(2) => given file is a file that can not be opened.
 * case(3) => given file has an invalid instruction.
 * case(4) => program is unable to malloc more memory.
 * case(5) => when (parameter) of instruction "push" is not an integer.
 * case(6) => stack is empty for pint.
 * case(7) => stack is empty for pop.
 * case(8) => When stack is short.
 */
void s_error(int err_c, ...)
{
	va_list ag;
	char *oper;
	int num;

	va_start(ag, err_c);
	switch (err_c)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
				va_arg(ag, char *));
			break;
		case 3:
			l_num = va_arg(ag, int);
			oper = va_arg(ag, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", num, oper);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(ag, int));
			break;
		default:
			break;
	}
	ffree_nodes();
	exit(EXIT_FAILURE);
}

/**
 * m_error - error handler.
 * @err_c : error codes are:
 * case(6) => stack it empty for pint.
 * case(7) => stack it empty for pop.
 * case(8) => stack is too short.
 * case(9) => Division by zero.
 */
void m_error(int err_c, ...)
{
	va_list ag;
	char *oper;
	int num;

	va_start(ag, err_c);
	switch (err_c)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n",
				va_arg(ag, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n",
				va_arg(ag, int));
			break;
		case 8:
			num = va_arg(ag, unsigned int);
			oper = va_arg(ag, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", num, oper);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n",
				va_arg(ag, unsigned int));
			break;
		default:
			break;
	}
	ffree_nodes();
	exit(EXIT_FAILURE);
}

/**
 * str_error - errors handler.
 * @err_c: error codes are :
 * case(10) ~> number inside a node is outside ASCII bounds.
 * case(11) ~> stack is empty.
 */
void str_error(int err_c, ...)
{
	va_list ag;
	int num;

	va_start(ag, err_c);
	num = va_arg(ag, int);
	switch (err_c)
	{
		case 10:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", num);
			break;
		case 11:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", num);
			break;
		default:
			break;
	}
	ffree_nodes();
	exit(EXIT_FAILURE);
}
