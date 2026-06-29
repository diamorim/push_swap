#include "../test.h"


Test(op_sa, basic)
{
	t_prog_state *state = init_prog_state();
	char *argv[] = {"2", "1", "3", "4", "5", NULL};
	parse_input(state, argv);
	t_stack *stack_a = state->a;
	t_node *current_node = stack_a->top;
	op_sa(state);
	//{1, 2, 3, 4, 5}
	for (size_t i = 0; i < 5; i++)
	{
		if (current_node == stack_a->top)
		{
			cr_expect(current_node->prev->value == 5);
			cr_expect(current_node->next->value == 2);
		}
		else if (current_node == stack_a->top->prev){
			cr_expect_eq(current_node->next->value, 1,  "expeceted: %d and got: %d", current_node->next->value, 1);
			cr_expect_eq(current_node->prev->value, 4, "expeceted: %d and got: %d", current_node->prev->value, 1);
		}
		else
		{
			cr_expect(current_node->next->value == current_node->value + 1);
			cr_expect(current_node->prev->value == current_node->value - 1, "%d");
		}
		current_node = current_node->next;
	}
	cr_expect(stack_a->size == 5);
}

Test(op_sb, basic)
{
	t_prog_state *state = init_prog_state();
	char *argv[] = {"2", "1", "3", "4", "5", NULL};
	//{4,3,1,2,5}

	parse_input(state, argv);
	while (state->a->size > 2){
		op_pb(state);
	}//3, 1, 2

	op_sb(state);
	//1, 3, 2
	t_stack *stack_b = state->b;
	t_node *current_node = stack_b->top;
	//{1, 2, 3}
	cr_assert(stack_b != NULL);
	cr_assert(stack_b->top != NULL);
	cr_expect_eq(current_node->value, 1, "%d", current_node->value);
	cr_expect_eq(current_node->next->value, 3, "%d", current_node->next->value);
	cr_expect_eq(current_node->prev->value, 2, "%d", current_node->prev->value);
	cr_expect_eq(state->ops_count_per_type[OP_SB], 1);
	cr_expect_eq(state->ops_count_total, 4);
	cr_expect(stack_b->size == 3);
}

Test(op_ss, basic)
{
	t_prog_state *state = init_prog_state();
	char *argv[] = {"1", "2", "3", "4", "5", "6", NULL};
	parse_input(state, argv);
	t_stack *stack_a = state->a;
	t_stack *stack_b = state->b;
	op_pb(state);
	op_pb(state);
	op_pb(state);

	int a[] = {4, 5, 6};
	int b[] = {3, 2, 1};

	expect(stack_a, a, 3);
	expect(stack_b, b, 3);
}