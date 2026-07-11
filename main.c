/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norobins <norobins@student.42Berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 16:21:03 by diamo             #+#    #+#             */
/*   Updated: 2026/07/11 22:59:38 by norobins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		run_prog(t_prog_state *state);
static int	error_exit(t_prog_state *state);

int	main(int argc, char **argv)
{
	t_prog_state	*state;

	if (argc < 2)
		return (0);
	if (!check_errors(argc, argv))
		return (error_exit(NULL));
	state = init_prog_state();
	if (!state)
		return (error_exit(NULL));
	if (!parse_input(state, argv + 1))
		return (error_exit(state));
	state->strat_req = strategy_from_argv(argv + 1);
	state->bench = bench_from_argv(argv + 1);
	run_prog(state);
	if (state->bench)
		print_bench_report(state);
	free_prog_state(state);
	return (0);
}

void	run_prog(t_prog_state *state)
{
	if (!state || !state->a || state->a->size == 0)
		return ;
	if (is_sorted_asc(state->a))
		return ;
	state->disorder = compute_disorder(state->a);
	dispatch_algo_strategy(state);
}

static int	error_exit(t_prog_state *state)
{
	free_prog_state(state);
	write(2, "Error\n", 6);
	return (1);
}
