#include "monty.h"

/**
 * push - function to put data on a stack
 * @h: double pointer
 * @data: integer
 * Return: always success
 */
void push(stack_t **h, unsigned int data)
{
	stack_t *newnode = malloc(sizeof(stack_t));

	if (newnode == NULL)
	{
		fprintf(stderr, "Error: Unable to allocate memory for new node\n");
		exit(EXIT_FAILURE);
	}

	newnode->n = data;
	newnode->next = *h;
	newnode->prev = NULL;

	if (*h != NULL)
	{
		(*h)->prev = newnode;
	}

	*h = newnode;
}
/**
 * pall - function to print everything on a stack
 * @head: double pointer
 * @d: integer
 * Return: always success
 */
void pall(stack_t **head, unsigned int d)
{
	stack_t *current = *head;
	(void)d;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
