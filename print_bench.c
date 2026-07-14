/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bench.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diamo <diamo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 23:00:05 by norobins          #+#    #+#             */
/*   Updated: 2026/07/14 19:38:15 by diamo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_percent_2dp(double d, int fd)
{
	int	whole;
	int	frac;

	if (d < 0)
		d = 0;
	if (d > 1)
		d = 1;
	d *= 100;
	whole = (int)d;
	frac = (int)((d - whole) * 100 + 0.5);
	if (frac >= 100)
	{
		whole++;
		frac -= 100;
	}
	ft_putnbr_fd(whole, fd);
	ft_putchar_fd('.', fd);
	ft_putchar_fd('0' + frac / 10, fd);
	ft_putchar_fd('0' + frac % 10, fd);
}

static void	print_strategy_line(t_strategy s)
{
	if (s == SIMPLE)
		ft_putstr_fd("simple (O(n^2))\n", 2);
	else if (s == MEDIUM)
		ft_putstr_fd("medium (O(n sqrroot n))\n", 2);
	else if (s == COMPLEX)
		ft_putstr_fd("complex (O(n log n))\n", 2);
	else
		ft_putstr_fd("adaptive (O(n^2) worst / O(n log n) typical)\n", 2);
}

static void	print_op_breakdown(t_prog_state *state)
{
	const char	*op_labels[OP_TYPES_TOTAL] = {
		"sa", "sb", "ss", "pa", "pb",
		"ra", "rb", "rr", "rra", "rrb", "rrr"
	};
	int			i;

	i = 0;
	while (i < OP_TYPES_TOTAL)
	{
		ft_putstr_fd((char *)op_labels[i], 2);
		ft_putstr_fd(": ", 2);
		ft_putnbr_fd(state->ops_count_per_type[i], 2);
		ft_putchar_fd('\n', 2);
		i++;
	}
}

void	print_bench_report(t_prog_state *state)
{
	if (!state || !state->bench)
		return ;
	ft_putstr_fd("--- benchmark ---\n", 2);
	ft_putstr_fd("disorder: ", 2);
	print_percent_2dp(state->disorder, 2);
	ft_putstr_fd("%\n", 2);
	ft_putstr_fd("strategy: ", 2);
	print_strategy_line(state->strat_used);
	ft_putstr_fd("total ops: ", 2);
	ft_putnbr_fd(state->ops_count_total, 2);
	ft_putchar_fd('\n', 2);
	print_op_breakdown(state);
}
