#include "monty.h"

/**
 * pall - Prints all the elements of the stack.
 * @stack: Double pointer to the stack.
 * @line_number: Line number of the opcode being executed.
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	(void)line_number;

	temp = *stack;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
