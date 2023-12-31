#include "monty.h"

/**
 * mod - Computes the remainder of the division of the second top
 *       element of the stack by the top element of the stack.
 * @stack: Double pointer to the stack
 * @line_number: Line number of the opcode being executed
 */

void mod(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n %= (*stack)->n;
	*stack = (*stack)->next;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
