/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diamo <diamo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 18:35:16 by diamo             #+#    #+#             */
/*   Updated: 2026/07/10 13:29:30 by diamo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		if (result > LONG_MAX / 10 || (result == LONG_MAX / 10
				&& (*str - '0') > LONG_MAX % 10))
		{
			if (sign == 1)
				return (LONG_MAX);
			return (LONG_MIN);
		}
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
