#include "monty.h"
/**
 *pstr - ....
 * @stack: .....
 * @line_number: ....
 *Return: ....
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	int i;
	stack_t *ptr = *stack;

	if (ptr != NULL)
	{
		if (ptr->n == 0)
			return;
	}
	for (; ptr; ptr = ptr->next)
	{
		i = ptr->n;
		if (i > 0 && i <= 127)
			putchar(ptr->n);
		else
			break;
	}
	putchar(10);
	(void)line_number;
}
