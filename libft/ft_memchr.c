/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damorim- <damorim-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 16:29:30 by damorim-          #+#    #+#             */
/*   Updated: 2026/06/02 16:57:26 by damorim-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*p;
	unsigned char	target;

	p = (unsigned char *)s;
	target = (unsigned const char)c;
	while (n > 0)
	{
		if (*p == target)
			return ((void *)p);
		p++;
		n--;
	}
	return (NULL);
}
