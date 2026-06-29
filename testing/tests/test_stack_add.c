#include <criterion/criterion.h>
#include "../../push_swap.h"

Test(stack_add_back, basic)
{
	t_node *node1 = new_node(1);
	t_node *node0 = new_node(0);
	t_stack *stack = init_stack();
	stack_add_back(stack, node1);

	cr_assert(stack != NULL);
	cr_assert(stack->top != NULL);
	cr_expect(stack->top == node1);
	cr_expect(stack->top->value == 1);
	cr_expect(stack->top->next == node1);
	cr_expect(stack->top->prev == node1);

	stack_add_back(stack, node0);

	cr_assert(stack != NULL);
	cr_assert(stack->top != NULL);
	cr_expect(stack->top == node1);
	cr_expect(stack->top->value == 1);
	cr_expect_eq(stack->top->next->value, 0, "result: %d, expected; %d", stack->top->next->value, 1);
	cr_expect_eq(stack->top->prev->value, 0, "result: %d, expected; %d", stack->top->next->value, 1);
	cr_expect(stack->top->next == node0);
	cr_expect(stack->top->prev == node0);
	cr_expect(stack->top->prev->next == node1);
	cr_expect(stack->top->prev->prev == node1);
}

Test(stack_add_front, basic)
{
	t_node *node1 = new_node(1);
	t_node *node0 = new_node(0);
	t_stack *stack = init_stack();
	
	stack_add_front(stack, node1);
	cr_assert(stack != NULL);
	cr_assert(stack->top != NULL);
	cr_expect(stack->top == node1);
	cr_expect(stack->top->next == node1);
	cr_expect(stack->top->prev == node1);
	cr_expect_eq(stack->top->value, 1);

	stack_add_front(stack,node0);

	cr_expect(stack->top == node0);
	cr_expect_eq(stack->size, 2);
	cr_expect_eq(stack->top->value, 0);
	cr_expect_eq(stack->top->prev->value, 1);
	cr_expect_eq(stack->top->next->value, 1);
	cr_expect(stack->top->next == node1);
	cr_expect(stack->top->prev == node1);
	cr_expect(stack->top->prev->next == node0);
	cr_expect(stack->top->prev->prev == node0);

	t_node *node11 = new_node(-1);
	stack_add_front(stack,node11);

	cr_expect(stack->top == node11);
	cr_expect(stack->top->prev == node1);
	cr_expect(stack->top->next == node0);
	cr_expect(node0->prev == node11);
	cr_expect(node0->next == node1);
	cr_expect(node1->next == node11);
	cr_expect(node1->prev == node0);
}