
#include <stdlib.h>
#include "stack.h"

STACK *stack_new()
{
	STACK *new = malloc(sizeof(STACK));
	new->top = NULL;
	new->size = 0;
	return new;
}

void stack_push(STACK *stack, TYPE *elem)
{
	struct STRSNODE *new = malloc(sizeof(struct STRSNODE));
	new->elem = elem;
	new->prev = stack->top;
	stack->top = new;
	stack->size++;
}

int stack_empty(STACK *stack)
{
	return stack->top == NULL;
}

TYPE *stack_pop(STACK *stack)
{
	TYPE *elem = NULL;
	struct STRSNODE *to_erase = stack->top;

	if (!stack_empty(stack))
	{
		elem = stack->top->elem;
		stack->top = stack->top->prev;
		free(to_erase);
		// stack->size--;
	}
	return elem;
}

TYPE *stack_peek(STACK *stack)
{
	TYPE *elem = NULL;

	if (!stack_empty(stack))
		elem = stack->top->elem;

	return elem;
}

void stack_destroy(STACK *stack)
{
	while (!stack_empty(stack))
		stack_pop(stack);

	free(stack);
}
