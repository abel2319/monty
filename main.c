#include "monty.h"

/**
 * main - entry of code
 *
 * Return: EXIT-SUCCESS if succeed
 * EXIT_FAILURE otherwize
 */
int main(int argc, char *argv[])
{
	FILE *stream;
	/*char *line = NULL;
	size_t len = 0;
	int nread = 1;*/
	char *line;
	int i = 0;
	char c;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	stream = fopen(argv[1], "r");
	if (stream == NULL)
	{
		perror("Error: Can't open file <file");
		exit(EXIT_FAILURE);
	}
	line = malloc(sizeof(char) * 256);
	verify_allocation(line);
	do
	{
		c = fgetc(stream);
		if (c != '\n')
		{
			line[i] = c;
		}
		else
		{
			i = -1;
			printf("%s\n", line);

			if (line != NULL)
			{
				free(line);
				line = malloc(sizeof(char)*256);
				verify_allocation(line);
			}
		}
		i++;
	} while (c != EOF);
	/*do
	{
		nread = getline(&line, &len, stream);
		fwrite(line, nread, 1, stdout);
		identify_opcode(line);
		free(line);
		nread = getline(&line, &len, stream);
	} while (nread != -1);*/

	/*free(line);*/
	fclose(stream);
	exit(EXIT_SUCCESS);
}
