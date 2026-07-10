/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_03_queries.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diamo <diamo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 13:55:18 by diamo             #+#    #+#             */
/*   Updated: 2026/07/10 12:09:42 by diamo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*	_____ find_pos_min() _____
  		Finds, and returns, the position
		in a given stack for the *smallest*
		value stored starting at the 'top'.

		The `top` of the stack is position `0`
		and the `bottom` of the stack is `size - 1`.

	Say we have a given stack with:
		position:	0		value	201
					1				132
					2				49
					3				98

					the pos_min would be 2 since
					49 has the position of the
					lowest value int the stack
*/
int	find_pos_min(t_stack *s)
{
	t_node	*curr;
	int		i;
	int		pos_min;
	int		val_min;

	if (!s || s->size <= 1)
		return (0);
	curr = s->top;
	pos_min = 0;
	val_min = curr->value;
	i = 0;
	while (i < s->size)
	{
		if (curr->value < val_min)
		{
			val_min = curr->value;
			pos_min = i;
		}
		curr = curr->next;
		i++;
	}
	return (pos_min);
}

/*	_____ find_pos_max() _____
  		Finds, and returns, the position
		in a given stack for the *largest/highest*
		value stored starting at the 'top'.

		The `top` of the stack is position `0`
		and the `bottom` of the stack is `size -1`.

		Say we have a given stack with:
			position:	0		value	201
						1				132
						2				49
						3				98

					the pos_max would be 0 since
					201 has the position of the
					highest value int the stack
*/
int	find_pos_max(t_stack *s)
{
	t_node	*curr;
	int		pos_max;
	int		val_max;
	int		i;

	if (!s || s->size <= 1)
		return (0);
	curr = s->top;
	pos_max = 0;
	val_max = curr->value;
	i = 0;
	while (i < s->size)
	{
		if (curr->value > val_max)
		{
			val_max = curr->value;
			pos_max = i;
		}
		curr = curr->next;
		i++;
	}
	return (pos_max);
}
