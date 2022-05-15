#include "monty.h"
/**
 * divv - result of division of  top stack number with the next number
 * @stack: pointer to linked list
 * @line_number: line number
 */
void divv(stack_t **stack, unsigned int line_number)
{
	int num = 0;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
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
		(*stack)->n /= num;
	}
}
