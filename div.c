#include "monty.h"
/**
 * div - check the code
 * @stack: number of arguments
 * @line_number: arguments
 * Return: Always EXIT_SUCCESS.
 */
void div(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		free(vars.buffer);
		free_list(stack);
		fclose(vars.stream);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free(vars.buffer);
		free_list(stack);
		fclose(vars.stream);
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	*stack = (*stack)->next;
	(*stack)->n /= tmp->n;
	free(tmp);
	tmp = NULL;
}
