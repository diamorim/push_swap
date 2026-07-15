/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damorim- <damorim-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 18:34:59 by diamo             #+#    #+#             */
/*   Updated: 2026/07/15 18:22:35 by damorim-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

int	parse_input(t_prog_state *state, char **argv)
{
	int		i;
	t_node	*node;

	if (!state || !state->a || !argv)
		return (0);
	i = 0;
	while (argv[i])
	{
		if (check_flags(argv[i]))
		{
			i++;
			continue ;
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
