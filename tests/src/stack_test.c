#include<stdio.h>
#include"acl_stack.h"

int push_test(struct acl_stack *stack, int value)
{
	if (acl_stack_push(stack, &value) != 0)
	{
		printf("Failed to push\n");
		return 1;
	}
	
	printf("Pushed %d\n", value);
	return 0;
}

int pop_test(struct acl_stack *stack)
{
	int value;
	if (acl_stack_pop(stack, &value) != 0)
	{
		printf("Failed to pop\n");
		return 1;
	}

	printf("Poped %d\n", value);
	return 0;
}

int
main()
{
	struct acl_stack *stack;
	stack = acl_create_stack(sizeof(int),1);

	//test push
	push_test(stack,147);
	push_test(stack,129);
	pop_test(stack);
	pop_test(stack);
	return 0;
}

