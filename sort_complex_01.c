/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex_01.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damorim- <damorim-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 18:02:17 by diamo             #+#    #+#             */
/*   Updated: 2026/07/15 18:25:02 by damorim-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		rank(t_prog_state *state);
int			count_bits(int n);
void		push_all_to_stack_a(t_prog_state *state);
static void	iterate_bits(t_prog_state *state, int bit, int stack_size);
static int	is_stack_a_sorted(t_prog_state *state);

/*	_____ sort_complex() _____
// For <=5 elements, function calls handle_small_sort
// due to its higher efficiency.
//
// For more than 5 elements, sort_complex
// calculates and assigns a rank to all of
// the values inside of a given stack using rank().
//
// Next, program uses a radix sort using binary.
//
// Let's assume two scenarios:
// - 100 unique elements in a stack
// - 500 unique elements in a stack
//
// In binary, 0-99 requires  7 bits
// 		  1100011
// 		  6543210
//
// In binary, a stack size of 500 (0-to-499) has 9 bits
// 		111110011
// 		876543210
//
// Program loops through the stack biggest_bit amount of
// times which is determined by the # of bits counted in
// the stack.
//
// So if there are 500 elements in a stack, then it would be
// 9 times.
//
// Then program compares the right-most bit to see
// if it's 1:
// 		- if so, program rotates the stack to examine the next element
// 		- if not, program pushes the element to stack 'b'
//
// Program does this for every element in the stack that is still
// residing in stack 'a'
//
// Once that round is finished, program uses push_all_to_stack_a()
// to push those back to stack `a` in linear order.
//
// After finishing that examination/sorting round, program increments to
// the next bit position.
//
//	Program does this until it has reviewed and compared every bit position.
//	In each pass, roughly half the elements (those with the current bit = 0)
//	are pushed to stack `b`, while the rest are rotated within stack `a`.
*/
void	sort_complex(t_prog_state *state)
{
	int	bit;
	int	biggest_bit;
	int	stack_size;

	if (state->a->size <= 5)
	{
		handle_small_sort(state);
		return ;
	}
	stack_size = state->a->size;
	rank(state);
	bit = 0;
	biggest_bit = count_bits(stack_size - 1);
	while (bit < biggest_bit)
	{
		iterate_bits(state, bit, stack_size);
		push_all_to_stack_a(state);
		if (is_stack_a_sorted(state))
			break ;
		bit++;
	}
}

static void	iterate_bits(t_prog_state *state, int bit, int stack_size)
{
	int	i;

	i = 0;
	while (i < stack_size)
	{
		if ((state->a->top->rank >> bit) & 1)
			op_ra(state);
		else
			op_pb(state);
		i++;
	}
}

/*	_____ count_bits _____
	// n   =   an integer for whom we are going to count the
//	number of bits
//
//	Function counts how many bits are needed to
//	represent a given number, `n`, before
//	the expression of a number in base-2 becomes
//	only 0s.
//
//	Let's say that we have:
//	111110011 (499 =
//		= 256 + 128 + 64 + 32 + 16 + 0 + 0 + 2 + 1
//		= 9 bit count
//
//		= 1111 (15   = 8 + 4 + 2 + 1)	= 4 bit count
//		= 0111 (7   =	   4 + 2 + 1)	= 3 bit count
//		= 0011 (3   =		   2 + 1)	= 2 bit count
//		= 0001 (1   =			   1)	= 1 bit count
//
//
//	Another example:
//		= 1011 (11	= 8 + 0 + 2 + 1)	= 4 bit count
//		= 0101 (5	=	  4 + 0 + 1)	= 3 bit count
//		= 0010 (2	=		  2 + 0)	= 2 bit count
//		= 0001 (1	=			  1)	= 1 bit count
//
//	With each passing of this loop in count_bits()
//	we divide 'n' by 2 and round down until it's 0.
//
//	The count will be everything until 0.
//
//	So if we started with:
//		- 499; next it would be
//		- 249; then
//		- 124;
//		- 62;
//		- 31;
//		- 15
//		- 7
//		- 3
//		- 1
//		- 0
//
//	So 499 would be 9 bits.
*/
int	count_bits(int n)
{
	int	bit_count;

	bit_count = 0;
	while (n > 0)
	{
		n = n >> 1;
		bit_count++;
	}
	return (bit_count);
}

void	push_all_to_stack_a(t_prog_state *state)
{
	int	i;
	int	target;

	target = state->b->size;
	i = 0;
	while (i < target)
	{
		op_pa(state);
		i++;
	}
}

static int	is_stack_a_sorted(t_prog_state *state)
{
	int		i;
	int		stack_size;
	t_node	*current_node;

	i = 0;
	stack_size = state->a->size;
	current_node = state->a->top;
	while (i < stack_size)
	{
		if (current_node->rank != i)
			return (0);
		current_node = current_node->next;
		i++;
	}
	return (1);
}
