#include "monty.h"
/**
 * pint - prints the value at the top of the stack, followed by a new line.
 * @h: double pointer
 * @data: integer
 */
void pint(stack_t **h, unsigned int data)
{
	stack_t *c = *h;

	if (*h == NULL)
	{
		fprintf(stderr, "L<%d>: can't pint, stack empty\n", data);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", c->n);
}
