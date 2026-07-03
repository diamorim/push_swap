#include "../test.h"

Test(radix_sort, sorts_five_elements)
{
	t_prog_state	*state = init_prog_state();
	char			*argv[] = {"40", "10", "30", "20", "50", NULL};
	int				expected[] = {10, 20, 30, 40, 50};

	parse_input(state, argv);
	radix_sort(state);

	cr_expect(is_sorted_asc(state->a), "stack a should be sorted ascending");
	cr_expect_eq(state->b->size, 0, "stack b should be empty after radix_sort but it has size %d and value %d", state->b->size, state->b->top->value);
	expect_stack(state->a, expected, 5);
}

Test(radix_sort, sorts_already_sorted)
{
	t_prog_state	*state = init_prog_state();
	char			*argv[] = {"1", "2", "3", "4", NULL};
	int				expected[] = {1, 2, 3, 4};

	parse_input(state, argv);
	radix_sort(state);

	cr_expect(is_sorted_asc(state->a));
	expect_stack(state->a, expected, 4);
}

Test(radix_sort, sorts_reverse_sorted)
{
	t_prog_state	*state = init_prog_state();
	char			*argv[] = {"9", "7", "5", "3", "1", NULL};
	int				expected[] = {1, 3, 5, 7, 9};

	parse_input(state, argv);
	radix_sort(state);

	cr_expect(is_sorted_asc(state->a));
	expect_stack(state->a, expected, 5);
}

Test(radix_sort, single_element_noop)
{
	t_prog_state	*state = init_prog_state();
	char			*argv[] = {"42", NULL};
	int				expected[] = {42};

	parse_input(state, argv);
	radix_sort(state);

	cr_expect(is_sorted_asc(state->a));
	expect_stack(state->a, expected, 1);
}

Test(radix_sort, sorts_negative_and_positive)
{
	t_prog_state	*state = init_prog_state();
	char			*argv[] = {"-5", "3", "-1", "0", "8", "-9", NULL};
	int				expected[] = {-9, -5, -1, 0, 3, 8};

	parse_input(state, argv);
	radix_sort(state);

	cr_expect(is_sorted_asc(state->a));
	expect_stack(state->a, expected, 6);
}