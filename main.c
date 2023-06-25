#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * get_line - Reads a line from a file stream.
 * @lineptr: Pointer to the buffer storing the line.
 * @n: Pointer to the size of the buffer.
 * @stream: File stream to read from.
 *
 * Return: Number of characters read, or -1 on failure.
 */

ssize_t get_line(char **lineptr, size_t *n, FILE *stream)
{
	size_t i;
	size_t bufsize = 0;
	char *newptr;
	int c;

	if (lineptr == NULL || n == NULL || stream == NULL)
		return (-1);
	bufsize = 0;
	if (*lineptr == NULL || *n == 0)
	{
		bufsize = 128;
		*lineptr = malloc(bufsize);
		if (*lineptr == NULL)
		{
			return (-1);
		}
		*n = bufsize;
	}
	i = 0;
	while ((c = fgetc(stream)) != EOF)
	{
		if (i >= *n - 1)
		{
			bufsize += 128;
			newptr = realloc(*lineptr, bufsize);
			if (newptr == NULL)
			{
				return (-1);
			}
			*lineptr = newptr;
			*n = bufsize;
		}
		(*lineptr)[i++] = c;
		if (c == '\n')
			break;
	}
	if (i == 0)
		return (-1);
	(*lineptr)[i] = '\0';
	return (i);
}

/**
 * main - Entry point of the program.
 * @argc: Number of command-line arguments.
 * @argv: Array of command-line arguments.
 *
 * Return: EXIT_SUCCESS on success, otherwise EXIT_FAILURE.
 */

int main(int argc, char *argv[])
{
	FILE *file;
	char *line = NULL, *opcode;
	size_t len = 0;
	ssize_t read;
	unsigned int line_number = 1;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((read = get_line(&line, &len, file)) != -1)
	{
		opcode = strtok(line, " \t\n");
		if (opcode != NULL && opcode[0] != '#')
			execute_instruction(&stack, opcode, line_number);
		line_number++;
	}
	free(line);
	fclose(file);
	free_stack(&stack);
	return (EXIT_SUCCESS);
}
