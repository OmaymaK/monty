#include "monty.h"
/**
 * push - pushes a new node to the end of a stack
 * @stack: pointer to stack
 * @line_number: number of the line
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *node;
	char *value=0;
	int i;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
	{
		printf("Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	if(value == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	for (i = 0; value[i] != '\0'; i++)
	{
		if(!(value[i] >= '0' && value[i] <= '9'))
		{
			fprintf(stderr,"L%u: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
	}
	node->n = atoi(value);
	node->prev = NULL;
	node->next = *stack;
	if (*stack == NULL)
		*stack = node;
	(*stack)->prev = node;
}
/**
 * pall - print the stacks's value
 * @stack: poiter to stack
 * @line_number: number of line
 */
void pall(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *tmp = *stack;

	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
