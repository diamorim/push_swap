#include "../test.h"

Test(op_ra, basic)
{
	t_prog_state *state = init_prog_state();
	char *argv[] = {"1", "2", "3", "4", "5", NULL};
	parse_input(state, argv);
	t_stack *stack_a = state->a;

	op_ra(state);

	int a[] = {2, 3, 4, 5, 1};

	expect_stack(stack_a, a, 5);

	t_prog_state *state1 = init_prog_state();
	char *argv1[] = {"1", NULL};
	parse_input(state1, argv1);
	t_stack *stack_a1 = state1->a;

	op_ra(state1);
	int a1[] = {1};

	expect_stack(stack_a1, a1, 1);

	t_prog_state *state2 = init_prog_state();
	char *argv2[] = {"1", "2", NULL};
	parse_input(state2, argv2);
	t_stack *stack_a2 = state2->a;

	op_ra(state2);
	int a2[] = {2, 1};

	expect_stack(stack_a2, a2, 2);
}

Test(op_rb, basic)
{
		t_prog_state *state = init_prog_state();
	char *argv[] = {"1", "2", "3", "4", "5", NULL};
	parse_input(state, argv);
	t_stack *stack_a = state->a;

	op_ra(state);

	int a[] = {2, 3, 4, 5, 1};

	expect_stack(stack_a, a, 5);

	t_prog_state *state1 = init_prog_state();
	char *argv1[] = {"1", NULL};
	parse_input(state1, argv1);
	t_stack *stack_a1 = state1->a;

	op_ra(state1);
	int a1[] = {1};

	expect_stack(stack_a1, a1, 1);

	t_prog_state *state2 = init_prog_state();
	char *argv2[] = {"1", "2", NULL};
	parse_input(state2, argv2);
	t_stack *stack_a2 = state2->a;

	op_ra(state2);
	int a2[] = {2, 1};

	expect_stack(stack_a2, a2, 2);
}