#include "monty.h"
/**
 * _free - function to free a stack
 * @stack: stack
 */
void _free(stack_t **stack)
{
	stack_t *tmp;

	if (stack == NULL)
		return;
	tmp = *stack;
	while (tmp)
	{
		*stack = tmp->next;
		free(tmp);
		tmp = *stack;
	}
}
/**
 * check_digit - function to check if its number or not
 * @value: value to check
 * Return: 0 or 1
 */
int check_digit(char *value)
{
	int i;

	if (value == NULL)
		return (0);
	for (i = 0; value[i] != '\0'; i++)
	{
		if (!(value[i] >= '0' && value[i] <= '9'))
			return (0);
	}
	return (1);
}
/**
 * push - pushes a new node to the end of a stack
 * @stack: pointer to stack
 * @line_number: number of the line
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
	{
		printf("Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	if (stack == NULL)
	{
		fprintf(stderr, "L%d: stack not found\n", line_number);
		exit(EXIT_FAILURE);
	}
	node->n = value;
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
