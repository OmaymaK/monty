#include "monty.h"
/**
 * rotl - check the code
 * @stack: number of arguments
 * @line_number: arguments
 * Return: Always EXIT_SUCCESS.
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr = *stack, *current = *stack;

	if (ptr == NULL || ptr->next == NULL)
		return;
	for (ptr->next; ptr = ptr->next)
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	ptr->next = current;
	current->prev = ptr;
	current->next = NULL;
	(void)line_number;
}
