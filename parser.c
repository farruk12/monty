#include "monty.h"

/**
 * parser - Executes the specified opcode.
 * @opcode: param
 * @stack: param
 * @line_number: The current line number.
 */
void parser(char *opcode, stack_t **stack, unsigned int line_number)
{
	if (strcmp(opcode, "push") == 0)
		push(stack, line_number);
	else if (strcmp(opcode, "pall") == 0)
		pall(stack, line_number);
	else if (strcmp(opcode, "pint") == 0)
		pint(stack, line_number);
	else if (strcmp(opcode, "pop") == 0)
		pop(stack, line_number);
	else if (strcmp(opcode, "swap") == 0)
		swap(stack, line_number);
	else if (strcmp(opcode, "add") == 0)
		add(stack, line_number);
	else if (strcmp(opcode, "nop") == 0)
		nop(stack, line_number);
	else
		monty_error("unknown instruction", line_number);
}

/**
 * monty_error - function to print error
 * @msg: The error message.
 * @line_number: Line number in the file.
 */
void monty_error(char *msg, unsigned int line_number)
{
	fprintf(stderr, "L%u: %s\n", line_number, msg);
	exit(EXIT_FAILURE);
}
