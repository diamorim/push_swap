/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_00_init.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diamo <diamo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 13:28:50 by diamo             #+#    #+#             */
/*   Updated: 2026/07/10 12:09:42 by diamo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	init_guards(t_prog_state *state)
{
	if (!state->a || !state->b)
	{
		if (state->a)
			free(state->a);
		if (state->b)
			free(state->b);
		free(state);
		return (0);
	}
	return (1);
}

/*
	__ init.c __

	__ Includes __
		- init_prog_state()
		- init_stack()
		- free_prog_state()
		- free_stack()

	___ Used by ___
		- main()

	___ Purpose ___
		- Try to allocate memory for the
		prog_state and stacks
	 	- Free memory for prog_state &
			stack when memory is no longer
			required.
*/

t_prog_state	*init_prog_state(void)
{
	t_prog_state	*state;
	int				i;

	state = malloc(sizeof(t_prog_state));
	if (!state)
		return (NULL);
	state->a = init_stack();
	state->b = init_stack();
	if (!init_guards(state))
		return (NULL);
	state->n = 0;
	state->ops_count_total = 0;
	i = 0;
	while (i < OP_TYPES_TOTAL)
		state->ops_count_per_type[i++] = 0;
	state->strat_req = ADAPTIVE;
	state->strat_used = ADAPTIVE;
	state->bench = 0;
	state->disorder = 0.0;
	return (state);
}

t_stack	*init_stack(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->top = NULL;
	stack->size = 0;
	return (stack);
}

void	free_prog_state(t_prog_state *state)
{
	if (!state)
		return ;
	if (state->a)
		free_stack(state->a);
	if (state->b)
		free_stack(state->b);
	free(state);
}

void	free_stack(t_stack *stack)
{
	t_node	*start;
	t_node	*current;
	t_node	*next;
	int		i;

	if (!stack)
		return ;
	if (!stack->top)
	{
		free(stack);
		return ;
	}
	start = stack->top;
	current = start;
	i = 0;
	while (i < stack->size)
	{
		next = current->next;
		free(current);
		current = next;
		i++;
	}
	free(stack);
}
