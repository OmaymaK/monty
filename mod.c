#include "monty.h"
/**
 * modd - gives the rest of division of the first by the second num in a stack
 * @stack: pointer to list
 * @line_number: number of line
 */
void modd(stack_t **stack, unsigned int line_number)
{
	int num = 0;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		_free(stack);
		exit(EXIT_FAILURE);
	}
	else if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		_free(stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		num = (*stack)->n;
		pop(stack, line_number);
		(*stack)->n %= num;
	}
}
