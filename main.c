#include "monty.h"
/**
 * main - main entry
 * @argc: Total of arguments
 * @argv: Arguments
 * Return: success or failure
 */
int main(int argc, char *argv[])
{
	FILE *file = NULL;
	stack_t *stack = NULL;
	int exit_code = EXIT_SUCCESS;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (exit_code);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file%s\n", argv[1]);
		return (exit_code);
	}
	execute_monty(file, &stack);
	fclose(file);
	return (exit_code);
}
