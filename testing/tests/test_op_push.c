#include "../test.h"


Test(op_pb, basic)
{
	t_prog_state *state = init_prog_state();
	char *argv[] = {"1", "2", "3", "4", "5", NULL};
	parse_input(state, argv);
	t_stack *stack_a = state->a;
	t_stack *stack_b = state->b;
	op_pb(state);
	int a[] = {2, 3, 4, 5};
	int b[] = {1};

	expect_stack(stack_a, a, 4);
	expect_stack(stack_b, b, 1);

	op_pb(state);

	int a1[] = {3, 4, 5};
	int b1[] = {2, 1};

	expect_stack(stack_a, a1, 3);
	expect_stack(stack_b, b1, 2);

		op_pb(state);

	int a2[] = {4, 5};
	int b2[] = {3, 2, 1};

	expect_stack(stack_a, a2, 2);
	expect_stack(stack_b, b2, 3);
}
Test(op_pa, basic)
{
	t_prog_state *state = init_prog_state();
	char *argv[] = {"5", "4", "3", "2", "1", NULL};
	t_stack *stack_a = state->a;
	t_stack *stack_b = state->b;
	parse_input(state, argv);
	while (stack_a->size > 0)
		op_pb(state);
	op_pa(state);
	int a[] = {1};
	int b[] = {2, 3, 4, 5};

	expect_stack(stack_a, a, 1);
	expect_stack(stack_b, b, 4);

	op_pa(state);
	int a1[] = {2 ,1};
	int b1[] = {3, 4 ,5};

	expect_stack(stack_a, a1, 2);
	expect_stack(stack_b, b1, 3);

	op_pa(state);
	int a2[] = {3, 2 ,1};
	int b2[] = {4 ,5};

	expect_stack(stack_a, a2, 3);
	expect_stack(stack_b, b2, 2);
}