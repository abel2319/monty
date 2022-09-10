#include "monty.h"

/**
 * push - push a new elt in the stack
 * @stack: stack
 * @line: new elt
 *
 */
void push(stack_t **stack, unsigned int line)
{
	stack_t *new = NULL;

	new = malloc(sizeof(stack_t));
	verify_allocation(new);
	new->n = line;
	if (*stack == NULL)
	{
		new->prev = NULL;
		new->next = NULL;
		*stack = new;
	}
	else
	{
		new->prev = (*stack);
		new->next = NULL;
		(*stack)->next = new;
		*stack = new;
	}
}

/**
 * pall - print all elts in the stack
 * @stack: stack
 * @line: line
 *
 */
void pall(stack_t **stack, __attribute__((unused)) unsigned int line)
{
	stack_t *tmp = *stack;

	if (tmp != NULL)
		while (tmp->prev != NULL)
			tmp = tmp->prev;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
/**
 * pint - print the elt at the head of the stack
 * @stack: stack
 * @line: line
 *
 */
void pint(stack_t **stack, unsigned int line)
{
	stack_t *tmp = *stack;

	if (tmp != NULL)
		printf("%d\n", tmp->n);
	else
	{
		printf("L%d: can't pint, stack empty", line);
		exit(EXIT_FAILURE);
	}
}
/**
 * pop - delete the first elts in the stack
 * @stack: stack
 * @line: line
 *
 */
void pop(stack_t **stack, unsigned int line)
{
	stack_t *tmp = *stack;

	if (tmp != NULL)
	{
		*stack = tmp->prev;
		free(tmp);
	}
	else
	{
		printf("L%d: can't pop an empty stack", line);
		exit(EXIT_FAILURE);
	}
}
