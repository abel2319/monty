#include "monty.h"
/**
 * _strlen - get te length of a string
 * @str: string
 *
 * Return: the length of string
 */
int _strlen(char *str)
{
	if (str == NULL || *str == '\0')
		return (0);

	return (1 + _strlen(str + 1));
}

int _strcmp(char *s1, char *s2)
{
	int i;

	if (_strlen(s1) == _strlen(s2))
	{
		for (i = 0; s1[i] != '\0'; i++)
			if (s2[i] == '\0' || (s1[i] != s2[i]))
				return (0);
		return (1);
	}
	return (0);
}

void (*get_opcode(char **s))(stack_t **, unsigned int)
{
	instruction_t ops[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};
	int i = 0, j = 0;

	while (ops[i].opcode != NULL)
	{
		j = _strcmp(s[0], ops[i].opcode);
		if (j == 1)
			return (ops[i].f);
		i++;
	}
	return (ops[i].f);
}
