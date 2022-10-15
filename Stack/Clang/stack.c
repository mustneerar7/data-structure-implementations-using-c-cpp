#include <stdio.h>

// defined size of stack
#define STACKSIZE 10

// structure of stack
struct stack {
	int top;
	int nodes[STACKSIZE];
};

// pushes values to stack variable
void push(struct stack *sp, int val) {

	if (sp->top == 9) {
		printf("Stack overflow\n");
	}
	else {
		++sp->top;
		sp->nodes[sp->top] = val;
	}
}

// pops values from stack varible
int pop(struct stack* sp) {
	if (sp->top == -1) {
		printf("Stack underflow\n");
	}
	else {
		int temp = sp->nodes[sp->top];
		--sp->top;

		return temp;
	}
	return 0;
}

// checks if stack is empty
int isEmpty(struct stack *sp) {
	if (sp->top == -1) {
		return 1;
	}
	else {
		return 0;
	}
}

// returns the top value of stack
// without popping
int getTop(struct stack *sp) {
	return sp->nodes[sp->top];
}

int main()
{

	// declare struct variable
	struct stack s;
	s.top = -1;

	// pushes values to stack
	push(&s, 3);
	push(&s, 4);

	// pops values from stack
	printf("%d \n", pop(&s));
	printf("%d \n", pop(&s));

	return 0;
}
