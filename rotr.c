#include "monty.h"
/**
 * rotr - check the code
 * @stack: number of arguments
 * @line_number: arguments
 * Return: Always EXIT_SUCCESS.
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr = *stack;

	if (ptr == NULL || ptr->next == NULL)
		return;
	for (; ptr->next; ptr = ptr->next)
		;
	ptr->prev->next = NULL;
	ptr->prev = NULL;
	ptr->next = *stack;
	(*stack)->prev = ptr;
	*stack = ptr;
	(void)line_number;
}
