#include "monty.h"

int verify_allocation(void *tmp)
{
	if (tmp == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
