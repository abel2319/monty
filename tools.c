#include "monty.h"

/**
 * verify_allocation - verify if a pointer is null or not
 * @tmp: the pointer
 *
 * Return: success or failure
 */
int verify_allocation(void *tmp)
{
	if (tmp == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

/**
 * verify_stream - verify if a FILE stream is null or not
 * @stream: the pointer to the file
 * @file: the name of file
 *
 * Return: success or failure
 */
int verify_stream(FILE *stream, char *file)
{
	if (stream == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file);
		exit(EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

/**
 * verify_argc - verify the nbr of args past to main
 * @argc: the number
 *
 * Return: success or failure
 */
int verify_argc(int argc)
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

/**
 * verify_int - verify the nbr of args past to main
 * @arg: the number
 * @l: the number of line
 * @s: the string converted
 *
 * Return: success or failure
 */
int verify_int(int arg, int l, char *s)
{
	if (s[0] == '0' || (s[0] == '-' && s[1] == '0'))
		return (EXIT_SUCCESS);
	if (arg == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", l);
		exit(EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
/**
 * verify_opc - verify if a function is an opcode
 * @f: the function
 * @op: the opcode
 * @l: the number of line
 *
 * Return: success or failure
 */
int verify_opc(void (*f)(stack_t **, unsigned int), char *op, int l)
{
	if (f == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", l, op);
		exit(EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
