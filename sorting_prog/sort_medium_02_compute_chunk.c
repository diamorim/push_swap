/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium_02_compute_chunk.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diamo <diamo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 18:16:23 by diamo             #+#    #+#             */
/*   Updated: 2026/07/08 18:17:12 by diamo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

#define MIN_CHUNK_SIZE 2

/*
	n is the number of elements in the stack.

	Function returns approximately the square root
	of the number of elements in the stack.

	(e.g. if	n = 100 c = 10,
				n = 17	c = 4
				n = 16	c = 4
				n = 15	c = 3
				n = 15	c = 3)
*/
int	compute_chunk_size(int n)
{
	int	guess;
	int	c;

	guess = 1;
	while (guess * guess <= n)
		guess++;
	c = (guess - 1);
	if (c < MIN_CHUNK_SIZE)
		c = MIN_CHUNK_SIZE;
	if (c > n)
		c = n;
	return (c);
}
