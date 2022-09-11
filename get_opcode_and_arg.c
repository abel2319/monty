#include "monty.h"
/**
 * count - get size of string
 * @line: where string is find
 * @i: pointer to save where we are in the line
 *
 * Return: the size of the string
 */
int count(char *line, int *i)
{
	int n = 0;
	char c = line[0];

	while (c != ' ' && c != '\0' && c != EOF && c != '\n')
	{
		n++;
		c =  line[*i];
		(*i)++;
	}
	return (n);
}
/**
 * identify_opcode - find opcode in the line read
 * @line: a monty statement
 * @s: where opcode is stored
 *
 * Return: SUCCESS or FAILURE
 */
char **identify_opcode(char **s, char *line)
{
	char c = line[0];
	int i = 0, j = 0, n = 0, t = 0;

	s = malloc(sizeof(char *) * 2);
	verify_allocation(s);
	while (c != '\0' && t != 2)
	{
		if (c != ' ')
		{
			n = count(line, &i);
			s[t] = malloc(sizeof(char) * n);
			verify_allocation(s[t]);
			i = i - n;
			j = i;
			c = line[i];
			while (c != ' ' && c != '\n')
			{
				if (t == 0)
					s[t][i - j] = line[i];
				else
				{
					if ((line[i] >= '0' && line[i] <= '9') || line[i] =='-')
						s[t][i - j] = line[i];
					else
					{
						free(s[1]);
						s[1] = "";
						break;
					}
				}
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
