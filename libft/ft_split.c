/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damorim- <damorim-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 20:02:21 by damorim-          #+#    #+#             */
/*   Updated: 2026/06/02 15:07:42 by damorim-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			count++;
		i++;
	}
	return (count);
}

void	free_split(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

static int	malloc_strs(char **str, char const *s, char c)
{
	int	i;
	int	len;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
		{
			len = 0;
			while (s[i + len] && s[i + len] != c)
				len++;
			str[j] = malloc(sizeof(char) * (len + 1));
			if (!str[j])
			{
				str[j] = NULL;
				free_split(str);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

static void	copy_strs(char **str, char *s, char c)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (!s[i])
			break ;
		k = 0;
		while (s[i] && s[i] != c)
		{
			str[j][k] = s[i];
			i++;
			k++;
		}
		str[j][k] = '\0';
		j++;
	}
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		words;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	str = malloc((words + 1) * sizeof(char *));
	if (!str)
		return (NULL);
	str[words] = NULL;
	if (!malloc_strs(str, s, c))
		return (NULL);
	copy_strs(str, (char *)s, c);
	return (str);
}
