/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damorim- <damorim-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 19:03:50 by diamo             #+#    #+#             */
/*   Updated: 2026/06/02 17:00:19 by damorim-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*p;
	size_t	s_len;

	s_len = ft_strlen(s);
	p = malloc(s_len + 1);
	if (!p)
		return (NULL);
	ft_strlcpy(p, s, s_len + 1);
	p[s_len] = '\0';
	return (p);
}
