#include "monty.h"

/**
 * add_to_the_stack - add a node to the stack
 * @new_node: pointer to the new node
 * @ln: interger representing the line number
 */
void add_to_the_stack(stack_t **new_node, _
		_attribute__((unused))unsigned int ln)
{
	stack_t *tmp;

	if (new_node == NULL || *new_node == NULL)

		exit(EXIT_FAILURE);

	if (head == NULL)

	{
		head = *new_node;
		return;
	}
	tmp = head;
	head = *new_node;
	head->next = tmp;
	tmp->prev = head;
}

/**
 * to_print_stack - add a node to the stack
 * @stack: pointer to a pointer
 * @line_number: line number
 */
void to_print_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	(void) line_number;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	tmp = *stack;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
/**
 * popout_top - adds a node to the stack
 * @stack: pointer to a pointer
 * @line_number: integer representing the line number
 */
void popout_top(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
		more_err(7, line_number);

	tmp = *stack;
	*stack = tmp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(tmp);
}
/**
 * to_print_top print the top node
 * @stack: pointer to a pointer
 * @line_number: interger
 */
void to_print_top(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
		more_err(6, line_number);
	printf("%d\n", (*stack)->n);
}
