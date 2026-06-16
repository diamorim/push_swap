/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumber.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diamo <diamo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 16:20:51 by diamo             #+#    #+#             */
/*   Updated: 2026/06/16 18:19:28 by diamo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}

int ft_isnumber(char *str)
{
	if (!str || !*str)
		return 0;
	
	if (*str == '-')
		str++;
	if (!*str)
		return 0;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return 0;
		str++;
	}
	return 1;
}