#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern int mode;

void free_stack(stack_t *stack);
int is_digit(const char *str);
void (*get_instruction_function(char *opcode))(stack_t **, unsigned int);
int execute_line(char *line, stack_t **stack, unsigned int line_number);
void push_stack_mode(stack_t **stack, stack_t *new_node);
void push_queue_mode(stack_t **stack, stack_t *new_node);
void handle_push(stack_t **stack, unsigned int line_number, char *argument);
void handle_pall(stack_t **stack, unsigned int line_number);
void handle_pint(stack_t **stack, unsigned int line_number);
void handle_pop(stack_t **stack, unsigned int line_number);
void handle_swap(stack_t **stack, unsigned int line_number);
void handle_add(stack_t **stack, unsigned int line_number);
void handle_nop(stack_t **stack, unsigned int line_number);
void handle_sub(stack_t **stack, unsigned int line_number);
void handle_div(stack_t **stack, unsigned int line_number);
void handle_mul(stack_t **stack, unsigned int line_number);
void handle_mod(stack_t **stack, unsigned int line_number);
void handle_pchar(stack_t **stack, unsigned int line_number);
void handle_pstr(stack_t **stack, unsigned int line_number);
void handle_rotl(stack_t **stack, unsigned int line_number);
void handle_rotr(stack_t **stack, unsigned int line_number);
void handle_stack(stack_t **stack, unsigned int line_number);
void handle_queue(stack_t **stack, unsigned int line_number);

#endif /* MONTY_H */
