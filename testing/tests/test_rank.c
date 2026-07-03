#include "../test.h"

Test(rank, assigns_correct_ranks)
{
	t_prog_state	*state = init_prog_state();
	char			*argv[] = {"40", "10", "30", "20", "50", NULL};
	t_node			*current_node;
	int				expected_ranks[] = {3, 0, 2, 1, 4};
	int				i;

	parse_input(state, argv);
	rank(state);

	current_node = state->a->top;
	i = 0;
	while (i < state->a->size)
	{
		cr_expect_eq(current_node->rank, expected_ranks[i],
			"value %d: expected rank %d but got %d",
			current_node->value, expected_ranks[i], current_node->rank);
		current_node = current_node->next;
		i++;
	}
}

Test(rank, single_element)
{
	t_prog_state	*state = init_prog_state();
	char			*argv[] = {"5", NULL};

	parse_input(state, argv);
	rank(state);

	cr_expect_eq(state->a->top->rank, 0);
}