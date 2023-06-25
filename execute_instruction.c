#include "monty.h"

void execute_instruction(stack_t **stack,
		char *opcode, unsigned int line_number)
{
	if (strcmp(opcode, "push") == 0)
		push(stack, line_number);
	else if (strcmp(opcode, "pop") == 0)
		pop(stack, line_number);
	else if (strcmp(opcode, "pall") == 0 || strcmp(opcode, "pall$") == 0)
		pall(stack, line_number);
	else if (strcmp(opcode, "pint") == 0)
		pint(stack, line_number);
	else if (strcmp(opcode, "add") == 0)
		add(stack, line_number);
	else if (strcmp(opcode, "sub") == 0)
		sub(stack, line_number);
	else if (strcmp(opcode, "div") == 0)
		divide(stack, line_number);
	else if (strcmp(opcode, "swap") == 0)
		swap(stack, line_number);
	else if (strcmp(opcode, "nop") == 0)
		nop(stack, line_number);
	else
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
		exit(EXIT_FAILURE);
	}
}
