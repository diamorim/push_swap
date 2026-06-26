#include <criterion/criterion.h>
#include "../../push_swap.h"


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
		}
		else if (current_node == stack_a->top->prev){
			cr_expect_eq(current_node->next->value, 1,  "expeceted: %d and got: %d", current_node->next->value);
			cr_expect_eq(current_node->prev->value, 4, "expeceted: %d and got: %d", current_node->prev->value);
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