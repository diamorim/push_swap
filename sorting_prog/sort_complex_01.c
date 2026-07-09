/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex_01.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diamo <diamo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 18:02:17 by diamo             #+#    #+#             */
/*   Updated: 2026/07/09 15:20:43 by diamo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rank(t_prog_state *state);
int		count_bits(int n);
void	push_all_to_stack_a(t_prog_state *state);
static void	iterate_bits(t_prog_state *state, int bit, int stack_size);


///
// ---- sort_complex ____
// Function calculates and assigns a rank to all of
// the values inside of a given stack using rank().
//
// Next, we use a radix sort using binary.
//
// Let's asume two scenarios:
// - 100 unqiue elements in a stack
// - 500 unique elements in a stack
//
// In binary, a stack size of 100 has 7 bits
// 		  1100100
// 		  6543210
//
// In binary, a stack size of 500 has 9 bits
// 		111110100
// 		876543210
//
// We loop through the stack biggest_bit amount of
// times which is detemined by the # of bits counted in
// the stack.
//
// So if we have 500 elements in a stack, the it would be
// 9 times.
//
// Then its comparing the right-most bit to see
// if it's 1:
// 		- if so, we rotate the stack to examine  the next element
// 		- if not, we push the element to stack 'b'
//
// We do this for every element in the stack that still residing in stack 'a'
//
// Once that round is finished, we use push_all_to_stack_a() to push those back to
// stack `a` in linear order.
//
// After finishing that examination/sorting round, we increment to
// the next bit position.
//
// We do this until we have reviewed and compared every bit position and
// pushed about half of the elements to stack `b` in descending order.
//
//
void	sort_complex(t_prog_state *state)
{
	int	bit;
	int	biggest_bit;
	int	stack_size;

	if (state->a->size <= 3)
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
		bit++;
	}
}

//
// _____ count_bits _____
// n	=	an integer for whom we are going to count the
// number of bits
//
// Function counts how many bits are neede to
// represent a given number, `n` before
// the expression of a number in base-2 becomes
// only 0s.
//
// Let's say that we have:
// 111110100 (500 =
// 				  = 256 + 128 + 64 + 32 + 0 + 8 + 0 + 0 + 0
// 				  = 9 bit count
//
//		1111 (15	= 8 + 4 + 2 + 1)	= 4 bit count
//		0111 (7	=     4 + 2 + 1)		= 3 bit count
//		0011 (3	=  		  2 + 1)		= 2 bit count
//		0001 (1	= 			  1)		= 1 bit count
//
//
// // Another example"
// 		 1011 (11	= 8 + 0 + 2 + 1)	= 4 bit count
// 		 0101 (5	=     4 + 0 + 1)	= 3 bit count
// 		 0010 (2	=  		  2 + 0)	= 2 bit count
// 		 0001 (1	= 			  1)	= 1 bit count
//
// 	With each passing of this loop in count_bits()
// we divide n by 2 and round down until its 0.
//
// The count will be everything until 0.
//
// So if we started with:
//		- 500; next it would be
//		- 250; then
// 		- 125;
// 		- 62;
// 		- 31;
// 		- 15
// 		- 7
// 		- 3
// 		- 1
// 		- 0
//
// So 500 would be 9 bits.
//
int	count_bits(int n)
{
	int bit_count;

	bit_count = 0;
	while (n > 0)
	{
		n = n >> 1;
		bit_count++;
	}
	return (bit_count);
}


//
// ____ push_all_to_stack_a ____
// Function pushes nodes from stack b to
// stack a from top to bottom (??)
//
// I, Noah, need to visualize this some more times.
//

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

//4, 3, 2, 1
//0100  0011   0010    0001
//stack a: 3, 1
//stack b: 4, 2
//stack a: 2, 4, 3, 1