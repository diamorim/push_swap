
/*
	__dispatch_algo_strategy()__
	This is used by prog_state() in main.c

	The function receives a stack which
	includes the "strategy" request (from the user
	or by default) in CLI to execute the strategy.

	__ Called by __
		- prog_state() in mainc.

	__ Includes
		- is_sorted_sc()
		- dispatch_algo_strategy()

	__ Uses __
		- is_sorted_asc()
		- sort_adaptive()
		- sort_simple()
		- sort_medium()
		- sort_complex()

	Function uses a simple dispatch pattern.

	__ Note about parameter(s) __
 */

void	dispatch_algo_strategy(t_prog_state *state)
{
	if (is_sorted_asc(state->a))
		return ;
	if (state->strategy == ADAPTIVE)
	{
		sort_adaptive(state);
		return ;
	}
	state->strat_used = state->strategy;
	if (state->strategy == SIMPLE)
		sort_simple(state);
	else if (state->strategy == MEDIUM)
		sort_medium(state);
	else if (state->strategy == COMPLEX)
		sort_complex(state);
}

/*
	__ is_sorted_asc() __ is used by
		- dispatch_algo_strategy()
		- sort_adaptive()

	Checks if a given stack (e.g. 'a') is
	sorted in ascending order.

	IMPORTANT :-)
		If the stack does not exist || is empty,
		|| or has only one node ||
		the stack is considered to be sorted &
		function returns (1).

	BASIC IDEA
		Function loops through the stack and looks
		at each node. If it finds one case where
		it is not sorted, the function returns (0)
		and stops the process.

		If the function cannot find a single case of
		'disorder' -- function returns (1)
		where the stack is not sorted --- then -- the
		function returns to the caller.
*/

int	is_sorted_asc(t_stack *s)
{
	t_node	*node;
	int		i;

	if (!s || s->size <= 1)
		return (1);
	node = s->top;
	i = 0;
	while (i < s->size - 1)
	{
		if (node->value > node->next->value)
			return (0);
		node = node->next;
		i++;
	}
	return (1);
}
