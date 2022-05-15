#include "monty.h"
/**
 * get_opcode - function get the right operation
 * @op: operation
 * @line_number: line number
 * @stack: pointer to list
 * Return: 0 or -1
 */
int get_opcode(char *op, unsigned int line_number, stack_t **stack)
{
	instruction_t operation[] = {
	{"push", push},
	{"pall", pall},
	{"pop", pop},
	{"swap", _swap},
	{"pint", pint},
	{"nop", nop},
	{"add", add},
	{"sub", sub},
	{"rotl", rotl},
	{"rotr", rotr},
	{"stack", stack2},
	{"queue", queue2},
	{NULL, NULL}
	};
	int i;

	for (i = 0; operation[i].opcode; i++)
	{
	if (strcmp(op, operation[i].opcode) == 0)
	{
	operation[i].f(stack, line_number);
	return (0);
	}
	}
	return (-1);
}
/**
 * execute_monty - function to execute monty
 * @file: file to open
 * @stack: stack
 */
void execute_monty(FILE *file, stack_t **stack)
{
	char *line = NULL, *token = NULL, *n = NULL;
	size_t size;
	unsigned int l = 0;

	while (getline(&line, &size, file) != EOF)
	{
		token = strtok(line, " \t\r\n");
		l++;
		if (token == NULL)
			continue;
		if (strcmp(token, "push") == 0)
		{
			n = strtok(NULL, " \t\r\n");
			if (check_digit(n) == 0)
			{
				fprintf(stderr, "L%u: usage: push integer\n", l);
				free(line);
				exit(EXIT_FAILURE);
			}
			value = atoi(n);
		}
		if (get_opcode(token, l, stack) == -1)
		{
			fprintf(stderr, "L%u: unknown instruction %s\n", l, token);
			free(line);
			_free(stack);
			exit(EXIT_FAILURE);
		}
	}
	free(line);
	_free(stack);
}
