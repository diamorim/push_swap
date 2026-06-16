/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damorim- <damorim-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 20:53:01 by diamo             #+#    #+#             */
/*   Updated: 2026/05/27 17:16:21 by damorim-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s_len;
	char	*p;

	s_len = ft_strlen(s1) + ft_strlen(s2);
	p = malloc((s_len + 1) * sizeof(char));
	if (!p)
		return (NULL);
	ft_strlcpy(p, s1, 1000);
	ft_strlcat(p, s2, s_len + 1);
	return (p);
}
