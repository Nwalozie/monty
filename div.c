#include "monty.h"

/**
 * divide - Divides the second element by the top element of the stack.
 * @stack: Double pointer to the stack.
 * @line_number: Line number of the opcode being executed.
 */

void divide(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n /= (*stack)->n;
	pop(stack, line_number);
}
