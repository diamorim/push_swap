/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diamo <diamo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 18:03:42 by diamo             #+#    #+#             */
/*   Updated: 2026/06/16 18:03:52 by diamo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_flags(char *str)
{
	if (!str)
		return 0;
	if (ft_strncmp(str, "--simple", 9) == 0 
		|| ft_strncmp(str, "--medium", 9) == 0
	 	|| ft_strncmp(str, "--adaptive", 11) == 0
		|| ft_strncmp(str, "--complex", 10) == 0)
		return 1;
	return 0;
}