/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diamo <diamo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 19:20:35 by diamo             #+#    #+#             */
/*   Updated: 2026/06/08 11:54:57 by diamo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substr;
	unsigned int	i;
	unsigned int	size;

	size = ft_strlen(s);
	i = 0;
	if (start > size)
		substr = ft_strdup("");
	if (start > size)
		return (substr);
	if (size - start >= len)
		substr = malloc((len + 1) * sizeof(char));
	else
		substr = malloc((size - start + 1) * sizeof(char));
	if (!substr)
		return (NULL);
	while (len > 0 && s[start])
	{
		substr[i] = s[start];
		i++;
		start++;
		len--;
	}
	substr[i] = '\0';
	return (substr);
}
