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
	int i = 0, t = 0, l = 0;
	char c;
	void (*f)(stack_t **, unsigned int);

	verify_argc(argc);
	stream = fopen(argv[1], "r");
	verify_stream(stream);
	line = malloc(sizeof(char) * 256);
	verify_allocation(line);
	do
	{
		c = fgetc(stream);
		printf("%c", c);
		if (c != '\n')
			line[i] = c;
		else
		{
			l++;
			tmp = identify_opcode(tmp, line);
			f = (*get_opcode)(tmp);
			verify_opc(f, tmp[1], l);
			if (f == push)
			{
				t = atoi(tmp[1]);
				verify_int(t, l);
			}
			f(&stack, t);
			i = -1;
			if (line != NULL)
			{
				free(line);
				line = malloc(sizeof(char) * 256);
				verify_allocation(line);
			}
		}
		i++;
	} while (c != EOF);
	fclose(stream);
	exit(EXIT_SUCCESS);
}
