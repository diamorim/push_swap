/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damorim- <damorim-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 13:31:43 by diamo             #+#    #+#             */
/*   Updated: 2026/06/02 16:30:12 by damorim-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned const char	*str1;
	unsigned const char	*str2;

	str1 = s1;
	str2 = s2;
	while (n > 0)
	{
		if (*str1 > *str2 || *str2 > *str1)
			return (*str1 - *str2);
		n--;
		str1++;
		str2++;
	}
	return (0);
}
