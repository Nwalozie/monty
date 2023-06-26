#include "monty.h"

/**
 * pstr - Prints the string contained in the stack.
 *        The string is a sequence of characters represented by
 *        the ASCII values until reaching a null byte, not a
 *        negative value, and within the printable range.
 * @stack: Double pointer to the stack
 * @line_number: Line number of the opcode being executed
 */

void pstr(stack_t **stack, unsigned int line_number)
{
        stack_t *current = *stack;

        while (current != NULL && current->n != 0 && current->n >= 32 && current->n <= 126)
        {
                putchar(current->n);
                current = current->next;
        }

        putchar('\n');
}
