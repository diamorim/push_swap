#include "../test.h"

Test(stack_to_arr, basic)
{
	t_prog_state *state = init_prog_state();
	char *argv[] = {"1", "2", "3", "4", "5", NULL};
	parse_input(state, argv);

	int *arr = stack_to_arr(state->a);
	int expected[] = {1, 2, 3, 4, 5};

	expect_arr(arr, expected, 5);
}