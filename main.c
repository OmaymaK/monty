#include "monty.h"
/**
 * main - main function
 */
int main(int argc, char *argv[])
{
	FILE *file;
	char * line_number = NULL;
	size_t length = 0;
	ssize_t read;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file%s\n", argv[1]);
		return (EXIT_FAILURE);
	}
	while ((read = getline(&line_number, &length, file)) != -1)
	{
		printf("%s", line_number);
	}
	if (line_number)
		free(line_number);
	
	exit(EXIT_SUCCESS);
}
