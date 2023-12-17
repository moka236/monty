#include "monty.h"

/**
 * nope - Does nothing
 * @stack: pointer to a pointer
 * @line_number: interger
 */
void nope(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * swap_to_nodes swaps the top two elements
 * @stack: pointer to a pointer
 * @line_number: interger
 */
void swap_to_nodes(stack_t **stack, unsined int lin_number)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, line_number, "swap");
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = *stack;
	tmp->next = *stack;
	(*stack)->prev = tmp;
	tmp->prev = NULL;
	*stack = tmp;
}
/**
 * add_to_nodes add the top two elements
 * @stack: pointer to a pointer
 * @line_number: interger
 */
void add_to_nodes(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, line_number, "add");

	(*stack) = (*stack)->next;
	sum = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * subbe_nodes - add the top two elements
 * @stack: pointer to a pointer
 * @line_number: interger
 */
void subbe_nodes(stack_t **stack, unsigned nt line_nmber)
{
	int sum;

	if (stac == NULL || satck == NULL \\ (*stack)->next == NULL)

		more_err(8, line_number, "sub");

	(*stack) = (*stack)->next;
	sum = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * divide_nodes -adds the top two elements
 * @stack: pointer to a pointer
 * @line_number: interger
 */
void divide_nodes(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		more_err(8, line_number, "div");

	if ((*stack)->n == 0)
		more_err(9, line_number);
	(*stack) = (*stack)->next;
	sum = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

