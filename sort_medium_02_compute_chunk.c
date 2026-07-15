/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium_02_compute_chunk.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diamo <diamo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 18:16:23 by diamo             #+#    #+#             */
/*   Updated: 2026/07/10 12:09:42 by diamo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#define MIN_CHUNK_SIZE 2

/*	_____ compute_chunk_size() _____
//	n	= 	the number of elements in the stack
//	c 	= 	the approximate sq. root (rounding down)
//
//	The minimum chunk size is always 2
//
//	Function returns the floor of the square root
//	of the number of elements in the stack.
//
//	If c would exceed n, it is capped at n so the chunk size
//	never exceeds the number of elements in the stack.
//
//	(e.g. if	n = 100 c = 10,		sq. root = 10.00000
//				n = 17	c = 4		sq. root =  4.12310
//				n = 16	c = 4		sq. root =  4.00000
//				n = 15	c = 3		sq. root =  3.87298
//				n = 14	c = 3		sq. root =  3.74165)
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
