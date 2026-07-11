/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diamo <diamo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 18:38:28 by diamo             #+#    #+#             */
/*   Updated: 2026/07/10 12:55:07 by diamo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_maxint(char **argv);
static int	reps_check(char **argv, int occ);
static int	is_argv_number(char *argv[]);
static int	is_argv_flags_repeated(char *argv[]);

int	check_errors(int argc, char **argv)
{
	if (argc < 2)
		return (0);
	argv++;
	if (count_strategy_flags(argv) > 1)
		return (0);
	if (!is_argv_number(argv))
		return (0);
	if (!check_maxint(argv))
		return (0);
	if (!is_argv_flags_repeated(argv))
		return (0);
	return (1);
}

static int	check_maxint(char **argv)
{
	long	val;

	if (!argv)
		return (0);
	while (*argv)
	{
		if (check_flags(*argv))
		{
			argv++;
			continue ;
		}
		val = ft_strtol(*argv);
		if (val > INT_MAX || val < INT_MIN)
			return (0);
		argv++;
	}
	return (1);
}

static int	reps_check(char **argv, int occ)
{
	int	occurences;

	occurences = 0;
	if (!argv)
		return (0);
	while (*argv)
	{
		if (check_flags(*argv))
		{
			argv++;
			continue ;
		}
		if (ft_atoi(*argv) == occ)
			occurences++;
		argv++;
	}
	return (occurences);
}

static int	is_argv_number(char *argv[])
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (check_flags(argv[i]))
		{
			i++;
			continue ;
		}
		if (!ft_isnumber(argv[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	is_argv_flags_repeated(char *argv[])
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (check_flags(argv[i]))
		{
			i++;
			continue ;
		}
		if (reps_check(argv, ft_atoi(argv[i])) > 1)
			return (0);
		i++;
	}
	return (1);
}
