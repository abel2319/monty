#include "monty.h"

int identify_opcode(char *line)
{
	char c;
	char *tmp = NULL;
	int i = 0, j = 0, n = 0;

	c = line[0];

	while (c != '\0')
	{
		n = 0;
		if (tmp != NULL)
			free(tmp);
		if (c != ' ')
		{
			while (c != ' ' && c != '\n')
			{
				n++;
				c =  line[i];
				i++;
			}
			tmp = malloc(sizeof(char) * n);
			if (tmp == NULL)
			{
				fprintf(stderr, "Error: malloc failed\n");
				return (EXIT_FAILURE);
			}
			i = i - n;
			j = i;
			c = line[i];
			while (c != ' ' && c != '\n')
			{
				tmp[i - j]= line[i];
				i++;
				c = line[i];
			}
			printf("%s\n", tmp);
		}
		i++;
		c = line[i];
	}
	return (1);
}
