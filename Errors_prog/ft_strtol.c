/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diamo <diamo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 17:36:32 by diamo             #+#    #+#             */
/*   Updated: 2026/06/25 19:05:26 by diamo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long	ft_strtol(char *str)
{
    long	result;
    int		sign;

    result = 0;
    sign = 1;
    if (!str)
        return 0;
    
    while (*str == ' ' || (*str >= 9 && *str <= 13))
        str++;
    if (*str == '-' || *str == '+')
    {
        if (*str == '-')
            sign = -1;
        str++;
    }
    while (*str >= '0' && *str <= '9')
    {
        result = result * 10 + (*str - '0');
        str++;
    }
    return (result * sign);
}
