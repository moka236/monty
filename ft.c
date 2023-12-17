#include "monty.h"

/**
 * open_file_1 - opens a file
 * @file_name: the file namepath
 * Return: void
 */

void open_file_1(char *file_name)
{
	FILE *fd_2 = fopen(file_name, "r");

	if (file_name == NULL || fd_2 == NULL)
		err(2, file_name);

	read_file(fd_2);
	fclose(fd_2);
}


/**
 * read_file_n - reads a file
 * @fd: pointer to file descriptor
 * Return: void
 */

void read_file_n(FILE *fd)
{
	int l_num, format = 0;
	char *buffer_1 = NULL;
	size_t len_l = 0;

	for (l_num = 1; getline(&buffer_1, &len_l, fd) != -1; l_num++)
	{
		format = parse_line(buffer_1, l_num, format);
	}
	free(buffer_1);
}


/**
 * parse_line_2 - Separates each line into tokens to determine
 * which function to call
 * @buffer: line from the file
 * @line_number: line number
 * @format:  storage format. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 * Return: Returns 0 if the opcode is stack. 1 if queue.
 */

int parse_line_2(char *buffer, int line_number, int format)
{
	char *opcode, *value_2;
	const char *delim_2 = "\n ";

	if (buffer == NULL)
		err(4);

	opcode = strtok(buffer, delim_2);
	if (opcode == NULL)
		return (format);
	value_2 = strtok(NULL, delim_2);

	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);

	find_func(opcode, value_2, line_number, format);
	return (format);
}

/**
 * find_func_m - find the appropriate function for the opcode
 * @opcode: opcode
 * @value: argument of opcode
 * @format:  storage format. If 0 Nodes will be entered as a stack.
 * @ln: line number
 * if 1 nodes will be entered as a queue.
 * Return: void
 */
void find_func_m(char *opcode, char *value, int ln, int format)
{
	int j;
	int flag_me;

	instruction_t func_list[] = {
		{"push", add_to_stack},
		{"pall", print_stack},
		{"pint", print_top},
		{"pop", pop_top},
		{"nop", nop},
		{"swap", swap_nodes},
		{"add", add_nodes},
		{"sub", sub_nodes},
		{"div", div_nodes},
		{"mul", mul_nodes},
		{"mod", mod_nodes},
		{"pchar", print_char},
		{"pstr", print_str},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (flag_me = 1, j = 0; func_list[j].opcode != NULL; j++)
	{
		if (strcmp(opcode, func_list[j].opcode) == 0)
		{
			call_fun(func_list[j].f, opcode, value, ln, format);
			flag_me = 0;
		}
	}
	if (flag_me == 1)
		err(3, ln, opcode);
}


/**
 * call_fun - Calls the required function.
 * @func: Pointer to the function that is about to be called.
 * @op: string representing the opcode.
 * @val: string representing a numeric value.
 * @ln: line numeber for the instruction.
 * @format: Format specifier. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 */
void call_fun(op_func func, char *op, char *val, int ln, int format)
{
	stack_t *node;
	int flag_me;
	int j;

	flag_me = 1;
	if (strcmp(op, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			flag_me = -1;
		}
		if (val == NULL)
			err(5, ln);
		for (j = 0; val[j] != '\0'; j++)
		{
			if (isdigit(val[j]) == 0)
				err(5, ln);
		}
		node = create_node(atoi(val) * flag);
		if (format == 0)
			func(&node, ln);
		if (format == 1)
			add_to_queue(&node, ln);
	}
	else
		func(&head, ln);
}
