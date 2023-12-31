#include "monty.h"
/**
 * mul - Multiplies the second top element of the stack
 *       with the top element of the stack.
 * @stack: Double pointer to the stack
 * @line_number: Line number of the opcode being executed
 */

void mul(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n *= (*stack)->n;
	*stack = (*stack)->next;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
