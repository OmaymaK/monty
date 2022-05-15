#include "monty.h"
/**
 * mult - multiplies the top stack num with the second 
 * @stack: pointer to linked list
 * @line_number: number of the line
 */
void mult(stack_t **stack, unsigned int line_number)
{
	int num = 0;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		_free(stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		num = (*stack)->n;
		pop(stack, line_number);
		(*stack)->n *= num;
	}
}
