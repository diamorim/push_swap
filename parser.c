#include "push_swap.h"

int	parse_input(t_prog_state *state, char **argv)
{
	int		i;
	t_node	*node;

	i = 0;
	// argv[0] is program name, we skip it
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
