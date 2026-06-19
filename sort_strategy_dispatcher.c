
/*
	__dispatch_algo_strategy()__
	This is used by prog_state() in main.c

	The function receives a stack which
	includes the "strategy" request (from the user
	or by default) in CLI to execute the strategy.

	Function uses a simple dispatch pattern.
 */

void	dispatch_algo_strategy(t_prog_state *prst)
{
	if (is_sorted_asc(prst->a))
		return ;
	if (prst->strategy == ADAPTIVE)
	{
		sort_adaptive(prst);
		return ;
	}
	prst->adaptive_used = prst->strategy;
	if (prst->strategy == SIMPLE)
		sort_simple(prst);
	else if (prst->strategy == MEDIUM)
		sort_medium(prst);
	else if (prst->strategy == COMPLEX)
		sort_complex(prst);
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
