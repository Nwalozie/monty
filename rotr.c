#include "monty.h"

#include "monty.h"

/**
 * rotr - Rotates the stack to the bottom.
 *        The last element becomes the first one.
 * @stack: Double pointer to the stack
 * @line_number: Line number of the opcode being executed
 */

void rotr(stack_t **stack, unsigned int line_number)
{
        stack_t *last;
        (void)line_number;

        if (*stack == NULL || (*stack)->next == NULL)
                return;

        last = *stack;
        while (last->next != NULL)
                last = last->next;

        last->next = *stack;
        (*stack)->prev = last;
        *stack = last;
        last->prev->next = NULL;
        last->prev = NULL;
}
