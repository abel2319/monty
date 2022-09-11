#include "monty.h"

/**
 * main - entry of code
 * @argc: number of arguments
 * @argv: all arguments
 *
 * Return: EXIT-SUCCESS if succeed
 * EXIT_FAILURE otherwize
 */
int main(int argc, char *argv[])
{
	stack_t *stack = NULL;
	FILE *stream;
	char *line, **tmp;
	int nread, l = 0, t = 0;
	size_t len = 0;
	void (*f)(stack_t **, unsigned int);

	verify_argc(argc);
	stream = fopen(argv[1], "r");
	verify_stream(stream, argv[1]);

	nread = getline(&line, &len, stream);
	while (nread != -1)
	{
		l++;
		tmp = identify_opcode(tmp, line);
		f = (*get_opcode)(tmp);
		verify_opc(f, tmp[0], l);
		if (f == push)
		{
			t = atoi(tmp[1]);
			verify_int(t, l, tmp[1]);
			f(&stack, t);
		}
		else
			f(&stack, l);
		nread = getline(&line, &len, stream);
	}

	free(line);
	fclose(stream);
	exit(EXIT_SUCCESS);
}
