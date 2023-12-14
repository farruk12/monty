#include "monty.h"

/**
 *parser - function that connects the monty commands to their respective
 *cutom function
 *@line: buffer
 *@stack: DLL
 *@line_number: line number
 */
void parser(char *line, stack_t **stack, unsigned int line_number)
{
	char *opcode, *argument;
	int i;

	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{NULL, NULL} /* Sentinel for the end of the instruction list */
	};

	opcode = strtok(line, " \t\n");
	if (opcode == NULL || opcode[0] == '#')
		return; /* Ignore empty lines and comments */

	argument = strtok(NULL, " \t\n");

	for (i = 0; instructions[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, instructions[i].opcode) == 0)
		{
			if (strcmp(opcode, "push") == 0)
			{
				if (argument == NULL || !is_number(argument))
				{
					fprintf(stderr, "L%u: usage: push integer\n", line_number);
					exit(EXIT_FAILURE);
				}
				instructions[i].f(stack, atoi(argument));
			}
			else
			{
				instructions[i].f(stack, line_number);
			}
			return;
		}
	}

	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
	exit(EXIT_FAILURE);
}

/**
 *is_number - function that checks if the string is digit
 *@str: string to be checked
 *Return: always success
 */
int is_number(const char *str)
{
	const char *c;

	if (str == NULL || *str == '\0')
		return (0);

	for (c = str; *c != '\0'; c++)
	{
		if (!isdigit(*c) && (*c != '-' || *c != '+' || *c != ' '))
			return (0);
	}

	return (1);
}
