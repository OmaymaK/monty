#include "monty.h"
/**
 *_div - ....
 * @stack: pointer
 * @line_number: The current working line number of a Monty bytecodes file
 *Return: ...
 */
void _div(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->next->n == 0)
	{
		fprintf(stderr, "L%d:  division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->next->n /= (*stack)->next->n;
	pop(stack, line_number);
}

