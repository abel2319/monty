#include "monty.h"

/**
 * identify_opcode - 
 * @line: a monty statement
 *
 * Return: SUCCESS or FAILURE
 */
char** identify_opcode(char **s, char *line)
{
	char c;
	int i = 0, j = 0, n = 0, t = 0;

	s = malloc(sizeof(char*) * 2);
	verify_allocation(s);
	c = line[0];
	while (c != '\0' && t != 2)
	{
		n = 0;
		if (c != ' ')
		{
			while (c != ' ' && c != '\0' && c != EOF && c != '\n')
			{
				n++;
				c =  line[i];
				i++;
			}
			s[t] = malloc(sizeof(char) * n);
			verify_allocation(s[t]);
			i = i - n;
			j = i;
			c = line[i];
			while (c != ' ' && c != '\n')
			{
				s[t][i - j]= line[i];
				i++;
				c = line[i];
			}
			t++;
		}
		i++;
		c = line[i];
	}

	return (s);
}
