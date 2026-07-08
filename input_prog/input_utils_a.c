/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diamo <diamo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 18:35:16 by diamo             #+#    #+#             */
/*   Updated: 2026/07/08 18:55:38 by diamo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	I (Noah :-) would propose to put some of the utilities
	related to input here:
		- is_number.c()
		- ft_strol.c()
		- int check_errors()
		- int check_maxint()
		- int reps_check()

	This would tidy up files as well as main.c

	Are we allowed to put files in folders? I think we
	we are not :-(


// removing #include/libft.h because it's already in push_swap.h
// ft_isdigit because it's in libft already


*/
#include "../push_swap.h"

#define LONG_MAX_DIV (LONG_MAX / 10)
#define LONG_MAX_MOD (LONG_MAX % 10)

int	ft_isnumber(char *str)
{
	if (!str || !*str)
		return (0);
	if (*str == '-')
		str++;
	if (!*str)
		return (0);
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

long	ft_strtol(char *str)
{
	long	result;
	int		sign;

	if (!str)
		return (0);
	result = 0;
	sign = 1;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		if (result > LONG_MAX_DIV || (result == LONG_MAX_DIV
				&& (*str - '0') > LONG_MAX_MOD))
			return (sign == 1 ? LONG_MAX : LONG_MIN);
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * sign);
}

t_strategy	strategy_from_argv(char **argv)
{
	int	i;

	if (!argv)
		return (ADAPTIVE);
	i = 0;
	while (argv[i])
	{
		if (ft_strncmp(argv[i], "--simple", 9) == 0)
			return (SIMPLE);
		if (ft_strncmp(argv[i], "--complex", 10) == 0)
			return (COMPLEX);
		if (ft_strncmp(argv[i], "--medium", 9) == 0)
			return (MEDIUM);
		if (ft_strncmp(argv[i], "--adaptive", 11) == 0)
			return (ADAPTIVE);
		i++;
	}
	return (ADAPTIVE);
}
