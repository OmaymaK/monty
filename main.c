#include "monty.h"
/**
 * main - main entry
 * @argc: Total of arguments
 * @argv: Arguments
 * Return: .....
 */
int main(int argc, char *argv[])
{
	FILE *file;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file%s\n", argv[1]);
		return (EXIT_FAILURE);
	}
	execute_monty(file, &stack);
	fclose(file);
	return (EXIT_SUCCESS);
}
