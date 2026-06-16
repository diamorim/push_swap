/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damorim- <damorim-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 18:01:46 by diamo             #+#    #+#             */
/*   Updated: 2026/06/02 16:13:09 by damorim-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*p;

	if (nmemb == 0 || size == 0)
	{
		p = malloc(0);
		return (p);
	}
	if (nmemb > __INT_MAX__ || size > __INT_MAX__)
		return (NULL);
	if (nmemb * size > __INT_MAX__)
		return (NULL);
	p = (char *)malloc(nmemb * size);
	ft_bzero(p, nmemb * size);
	return (p);
}
