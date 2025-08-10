

#ifndef STACK_H_
#define STACK_H_

#include "datatypes.h"

struct STRSNODE {
	TYPE *elem;
	struct STRSNODE *prev;
};

typedef struct {
	struct STRSNODE *top;
	int size;
} STACK;

STACK *stack_new();
void stack_push(STACK *stack,TYPE *elem);
int stack_empty(STACK *stack);
TYPE *stack_pop(STACK *stack);
TYPE *stack_peek(STACK *stack);
void stack_destroy(STACK *stack);

#endif /* STACK_H_ */
