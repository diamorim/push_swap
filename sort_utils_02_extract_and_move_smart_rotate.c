/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_02_extract_and_move_smart_rotate        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diamo <diamo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 18:19:45 by diamo             #+#    #+#             */
/*   Updated: 2026/07/10 12:09:42 by diamo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	execute_rotation(t_prog_state *state, t_stack *s, int steps,
				int reverse_flag);

/*	_____ extract_move_lowest_to_stack_b() _____
//		One by one, this function pushes
//		everything from stack a to stack b
//		except for the three largest values.
//
//		Note that the function uess 'smart_rotate'
// 		to figure out what is the most efficient direction
//		to get the element with the smallest value to the top.
*/
void	extract_move_lowest_to_stack_b(t_prog_state *state)
{
	int	min_pos;

	while (state->a->size > 3)
	{
		min_pos = find_pos_min(state->a);
		smart_rotate(state, state->a, min_pos);
		op_pb(state);
	}
}

/*	_____ smart_rotate() _____
//		- Attempts to rotate nodes in a given stack with
//		the least number of ops possible.
//		- Brings a node at a specific position to the top
//		of a given stack.
//
//		- Calculates if the position of an element is closer
//		to the top or the bottom of the stack.
//
//		pos 0  ← top
//		...
//		pos 3
//		pos 4   ← midpoint (size/2 = 5)
//		pos 5
//		...
//		pos 9  ← bottom
//
//		- If the position of the element in the stack is in the:
//			- first half ----->   rotates forward
//			- second half ------> reverse rotates
//
 */
void	smart_rotate(t_prog_state *state, t_stack *s, int pos)
{
	int	reverse_flag;

	if (!state || !s)
		return ;
	if (pos == 0 || pos >= s->size)
		return ;
	if (pos <= s->size / 2)
	{
		reverse_flag = 0;
		execute_rotation(state, s, pos, reverse_flag);
	}
	else
	{
		reverse_flag = 1;
		execute_rotation(state, s, s->size - pos, reverse_flag);
	}
}

/*	_____ execute_rotation() _____
//	- Executes 'rotate' on a given stack based on instructions
//	from the caller -- smart_rotate()
//
//	Caller instructs:
//	- stack -- which stack to modify direction
//	- whether to rotate forwards or backwards
//
 */
static void	execute_rotation(t_prog_state *state, t_stack *s, int steps,
				int reverse_flag)
{
	int	i;

	i = 0;
	while (i < steps)
	{
		if (s == state->a)
		{
			if (reverse_flag)
				op_rra(state);
			else
				op_ra(state);
		}
		else
		{
			if (reverse_flag)
				op_rrb(state);
			else
				op_rb(state);
		}
		i++;
	}
}

/*	_____ ft_swop _____
// Swaps values between two integer pointers
//
// This function is called by partition() in
// sort_utils_03_rank.c -- which is used by rank()
// which is used by sort_medium() and sort_complex().
//
// It is not used elsewhere.
//
*/
void	ft_swop(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
