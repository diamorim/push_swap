/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damorim- <damorim-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 19:45:32 by damorim-          #+#    #+#             */
/*   Updated: 2026/06/02 18:44:03 by damorim-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	count_digits(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
		return (11);
	if (n == 0)
		return (1);
	if (n < 0)
	{
		count++;
		n = -n;
	}
	while (n > 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;

	len = count_digits(n);
	str = malloc((len + 1) * sizeof(char));
	str[len] = '\0';
	if (!str)
		return (NULL);
	if (n == -2147483648)
		ft_strlcpy(str, "-2147483648", 13);
	else
	{
		if (n < 0)
			str[0] = '-';
		if (n < 0)
			n = -n;
		while (n >= 10)
		{
			str[--len] = '0' + n % 10;
			n /= 10;
		}
		str[len - 1] = '0' + (n % 10);
	}
	return (str);
}
