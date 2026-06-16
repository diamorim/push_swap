/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diamo <diamo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 16:21:03 by diamo             #+#    #+#             */
/*   Updated: 2026/06/16 18:16:22 by diamo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int check_errors(int argc, char **argv);
int check_maxint(char **argv);
int reps_check(char **argv, int occ);

int	main(int argc, char **argv)
{
	t_program_state	*prog_state;

	if (argc == 1)
		return (0);
	if (!check_errors(argc, argv))
		write(1, "Error\n", 7);
	//prog_state = malloc(sizeof(t_prog_state)); i think you meant prog_state instead of t_progstate
	prog_state = malloc(sizeof(prog_state));
	if (!prog_state)
	{
		write(2, "Error\n", 6);
		return (1);
	}
//	init_prog_state(prog_state);
//	run_prog_state(prog_state, argc, argv);
	return (0);
}

int check_errors(int argc, char **argv)
{
	int i;

	i = 0;
	//i don't know if only one argument is valid as theres nothing to organize
	if (argc <= 2)
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
//checks if theres any argument that is higher than the maximum integer or lower than the minimum integer
int check_maxint(char **argv)
{
	//check if there's any argument
	if (!argv)
		return 0;
	//looping throught arguments and checking if they are between the maximum int and the minimum int
	while (*argv)
	{
		if (check_flags(*argv))
		{
			argv++;
			continue;
		}
		if (ft_strtol(*argv) > INT_MAX || ft_strtol(*argv) < INT_MIN)
			return 0;
		argv++;
	}
	return 1;
}
int reps_check(char **argv, int occ)
{
	int occurences;

	occurences = 0;
	while (*argv)
	{
		if (check_flags(*argv))
		{
			argv++;
			continue;
		}
		if (ft_atoi(*argv) == occ)
			occurences++;
		argv++;
	}
	return occurences;
}
