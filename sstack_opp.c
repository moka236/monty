#include "monty.h"

/**
 * the_mul_nodes - add the top two elements
 * @stack: pointer
 * @line_number: interger
 */
void the_mul_nodes(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, line_number, "mul");

	(*stack) = (*stack)->next;
	sum = (*stack)->n * (*stack)->preev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * the_mod_nodes - adds the top two elementd
 * @stack: pointer
 *
 * @line_number: interger
 */
void the_mod_nodes(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->nxt == NULL)

		more_err(8, line_number, ",od");

	if ((*stack)->n == 0)
		more_err(9, line_number);
	(*stack) == (*stack)->next;
	sum = (*stack)->n % (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
