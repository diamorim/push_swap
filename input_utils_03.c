/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils_03.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damorim- <damorim-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 16:27:35 by diamo             #+#    #+#             */
/*   Updated: 2026/07/15 18:23:11 by damorim-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_flags(char *str)
{
	if (!str)
		return (0);
	if (ft_strncmp(str, "--simple", 9) == 0
		|| ft_strncmp(str, "--medium", 9) == 0
		|| ft_strncmp(str, "--adaptive", 11) == 0
		|| ft_strncmp(str, "--complex", 10) == 0
		|| ft_strncmp(str, "--bench", 8) == 0)
		return (1);
	return (0);
}

int	check_allflags(char **argv)
{
	int	flags_count;

	flags_count = 0;
	if (!argv)
		return (0);
	while (*argv)
	{
		if (check_flags(*argv))
			flags_count++;
		argv++;
	}
	return (flags_count);
}

int	is_strategy_flag(char *str)
{
	if (!str)
		return (0);
	if (ft_strncmp(str, "--simple", 9) == 0
		|| ft_strncmp(str, "--medium", 9) == 0
		|| ft_strncmp(str, "--adaptive", 11) == 0
		|| ft_strncmp(str, "--complex", 10) == 0)
		return (1);
	return (0);
}

int	count_strategy_flags(char **argv)
{
	int	count;

	count = 0;
	if (!argv)
		return (0);
	while (*argv)
	{
		if (is_strategy_flag(*argv))
			count++;
		argv++;
	}
	return (count);
}
