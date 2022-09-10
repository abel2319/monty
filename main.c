#include "monty.h"
stack_t *stack = NULL;
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
	FILE *stream;
	char *line, **tmp;
	int nread, l = 0, t = 0;
	size_t len = 0;
	void (*f)(stack_t **, unsigned int);

	verify_argc(argc);
	stream = fopen(argv[1], "r");
	verify_stream(stream);

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
			verify_int(t, l);
		}
		f(&stack, t);
		nread = getline(&line, &len, stream);
	}

	free(line);
	fclose(stream);
	exit(EXIT_SUCCESS);
}
