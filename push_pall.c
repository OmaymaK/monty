#include "main.h"
/**
 * push - pushes a new node to the end of a stack
 * @stack: pointer to stack
 * @line_number: number of the line
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *node;
	char *value;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
	{
		printf("Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	node->n = atoi(value);
	node->prev = NULL;
	node->next = *stack;
	if (*stack == NULL)
		*stack = node;
	*stack->prev = node;
}
/**
 * pall - print the stacks's value
 * @stack: poiter to stack
 * @line_number: number of line
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
