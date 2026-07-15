/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sor_compute_disorder.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damorim- <damorim-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 18:01:31 by diamo             #+#    #+#             */
/*   Updated: 2026/07/15 18:24:29 by damorim-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_node(t_node *start, int remaining);

double	compute_disorder(t_stack *s)
{
	int		i;
	int		mistakes;
	int		total_pairs;
	t_node	*outer;

	if (!s || s->size < 2)
		return (0.0);
	mistakes = 0;
	total_pairs = 0;
	outer = s->top;
	i = 0;
	while (i < s->size)
	{
		mistakes += check_node(outer, s->size - i);
		total_pairs += (s->size - i - 1);
		outer = outer->next;
		i++;
	}
	return ((double)mistakes / (double)total_pairs);
}

static int	check_node(t_node *start, int remaining)
{
	int		disorder_count;
	int		j;
	t_node	*inner;

	if (!start)
		return (0);
	disorder_count = 0;
	inner = start->next;
	j = 0;
	while (j < remaining - 1)
	{
		if (start->value > inner->value)
			disorder_count++;
		inner = inner->next;
		j++;
	}
	return (disorder_count);
}
