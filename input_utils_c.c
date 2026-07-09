/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils_c.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diamo <diamo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 16:27:35 by diamo             #+#    #+#             */
/*   Updated: 2026/07/09 16:27:36 by diamo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_flags(char *str)
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