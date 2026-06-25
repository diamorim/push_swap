/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diamo <diamo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 16:21:03 by diamo             #+#    #+#             */
/*   Updated: 2026/06/25 19:34:18 by diamo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_prog_state	*prog_state;

	if (argc < 2)
		return (0);
	if (argc == 2 && ft_isnumber(argv[1]))
		return (0);
	if (!check_errors(argc, argv))
	{
		write(1, "Error\n", 7);
		return (1);
	}
	prog_state = init_prog_state();
	if (!prog_state)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if (!parse_input(prog_state, argv + 1))
	{
		free_prog_state(prog_state);
		write(2, "Error\n", 6);
		return (1);
	}
//	run_prog(prog_state, argc, argv);
	return (0);
}

int check_errors(int argc, char **argv)
{
	int i;

	i = 0;
	if (argc < 2)
		return 0;
	//adding 1 to arguments so that it is out of the first argument, that is the programs name
	argv++;
	//checking if there are any flags in the arguments
	if (check_allflags(argv) > 1)
		return 0;
	//loops tghrought the arguments and checks if theres any repetiton of numbers
	//checks if every argument is a number
	while (argv[i])
	{
		//skipping the flags for no interference
		if (check_flags(argv[i]))
		{
			i++;
			continue;
		}
		if (!ft_isnumber(argv[i]))
			return 0;
		i++;
	}
	i = 0;
	if (!check_maxint(argv))
		return 0;
	//looping throught argv and checking if theres any repeated number
	while (argv[i])
	{
		if (check_flags(argv[i]))
		{
			i++;
			continue;
		}
		if (reps_check(argv, ft_atoi(argv[i])) > 1)
			return 0;
		i++;
	}
	return 1;
}