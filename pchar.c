#include "monty.h"
/**
 * pchar - prints the char in the top 
 * @stack: pointer to list
 * @line_number: number of the line
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	if((*stack) == NULL || stack == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		_free(stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		if((*stack)->n >= 0 && (*stack)->n <= 127)
			printf("%c\n", (*stack)->n);
		else
		{
			fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
			_free(stack);
			exit(EXIT_FAILURE);
		}
	}
}
