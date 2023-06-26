#include "monty.h"

/**
 * rotl - Rotates the stack to the top.
 *        The first element becomes the last one.
 * @stack: Double pointer to the stack
 * @line_number: Line number of the opcode being executed
 */

void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *last = *stack;
	(void)line_number;
	if (*stack == NULL || (*stack)->next == NULL)
		return;

	while (last->next != NULL)
		last = last->next;

	last->next = *stack;
	(*stack)->prev = last;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last->next->next = NULL;
}
