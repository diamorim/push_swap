/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diamo <diamo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 16:21:03 by diamo             #+#    #+#             */
/*   Updated: 2026/06/26 15:03:38 by diamo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"


void	run_prog(t_prog_state *state)
{
	if (!state || !state->a || state->a->size == 0)
		return ;
	if (is_sorted_asc(state->a))
		return ;
	state->disorder = compute_disorder(state->a);
	dispatch_algo_strategy(state);
}

static int   error_exit(t_prog_state *state)
{
   free_prog_state(state);
   write(2, "Error\n", 6);
   return (1);
}

int	main(int argc, char **argv)
{
	t_prog_state	*state;

	if (argc < 2)
		return (0);
	if (argc == 2 && ft_isnumber(argv[1]))
		return (0);
	if (!check_errors(argc, argv))
		return (error_exit(NULL));
	state = init_prog_state();
	if (!state)
		return (error_exit(NULL));
	if (!parse_input(state, argv + 1))
		return (error_exit(state));
	run_prog(state);
	free_prog_state(state);
	return (0);
}
