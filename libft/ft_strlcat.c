/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diamo <diamo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 14:06:12 by damorim-          #+#    #+#             */
/*   Updated: 2026/06/08 12:51:33 by diamo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dstlen;
	size_t	i;

	dstlen = 0;
	i = 0;
	while (dstlen < size && dst[dstlen] != '\0')
		dstlen++;
	if (size > dstlen)
	{
		while (i < size - dstlen - 1 && src[i] != '\0')
		{
			dst[i + dstlen] = src[i];
			i++;
		}
		dst[dstlen + i] = '\0';
	}
	return (ft_strlen(src) + dstlen);
}
