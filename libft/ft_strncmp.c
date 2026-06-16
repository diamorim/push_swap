/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diamo <diamo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 19:19:53 by damorim-          #+#    #+#             */
/*   Updated: 2026/06/08 12:52:09 by diamo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && !(s1[i] == '\0' && s2[i] == '\0'))
	{
		if (s1[i] > s2[i] || s1[i] < s2[i])
		{
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		}
		else if ((s1[i] != '\0' && s2[i] == '\0') || (s1[i] == '\0'
				&& s2[i] != '\0'))
			return (s1[i]);
		i++;
	}
	return (0);
}
