/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diamo <diamo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 16:21:03 by diamo             #+#    #+#             */
/*   Updated: 2026/06/25 20:06:50 by diamo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_prog_state	*state;

	if (argc < 2)
		return (0);
	if (argc == 2 && ft_isnumber(argv[1]))
		return (0);
	if (!check_errors(argc, argv))
	{
		write(1, "Error\n", 7);
		return (1);
	}
	state = init_prog_state();
	if (!state)
	{
		write(2, "Error\n", 7);
		return (1);
	}
	if (!parse_input(state, argv + 1))
	{
		free_prog_state(state);
		write(2, "Error\n", 7);
		return (1);
	}
//	run_prog(state, argc, argv);
	free_prog_state(state);
	return (0);
}


/*
 * Changing '1' in "write(1, "Error\n", 7);" to
 * '2' because '2' is for the stderr
 *
 * Also fixing '6' in "write(2, "Error\n", 6);" to
 * '7' to allow for null terminator

 */
