#include "../push_swap.h"

#define MIN_CHUNK_SIZE 2

static int	compute_chunk_size(int n);
static void	restore_to_a(t_prog_state *state);

void	distribute_to_b(t_prog_state *state, int chunk_size,
			int num_chunks, int n);

/*
	The idea of this function is first split the stack
	into evenly sized chunks -- we do this to minimize the
	number of operations.

	We determind the # of chunks based on the approximate
	square root of the # of elements in the stack.
*/

void	sort_medium(t_prog_state *state)
{
	int	chunk_size;
	int	num_chunks;
	int	n;

	if (!state || !state->a)
		return ;
	if (handle_small_sort(state))
		return ;
	n = state->a->size;
	chunk_size = compute_chunk_size(n);
	num_chunks = (n + chunk_size - 1) / chunk_size;
	rank_stack(state->a);
	distribute_to_b(state, chunk_size, num_chunks, n);
	restore_to_a(state);
}

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
static int	compute_chunk_size(int n)
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

/*

*/
static void	restore_to_a(t_prog_state *state)
{
	while (state->b->size > 0)
	{
		smart_rotate(state, state->b, find_pos_max(state->b));
		op_pa(state);
	}
}
