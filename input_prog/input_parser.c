#include "../push_swap.h"

/*
	___ Calls on ___
		- new_node()
		- stack_add_back()
		- both are located currently
		in stack_utils.c

	___ Notes ___
		Consider moving those functions here
		if we do not call them anywhere else.
*/

int	parse_input(t_prog_state *state, char **argv)
{
	int		i;
	t_node	*node;

	i = 0;
	while (argv[i])
	{
		if (check_flags(argv[i]))
		{
			i++;
			continue;
		}
		node = new_node(ft_atoi(argv[i]));
		if (!node)
			return (0);
		stack_add_back(state->a, node);
		i++;
	}
	state->n = state->a->size;
	return (1);
}
