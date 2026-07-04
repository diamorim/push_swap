#include "../push_swap.h"

static void	pull_band_elements(t_prog_state *state, int min,
				int max, int width);
static void	scan_one_band(t_prog_state *state, int band, int chunk_size,
				int n);

/*
	...
*/
void	distribute_to_b(t_prog_state *state, int chunk_size,
			int num_chunks, int n)
{
	int	i;

	i = 0;
	while (i < num_chunks)
	{
		scan_one_band(state, i, chunk_size, n);
		i++;
	}
}

/*

*/
static void	scan_one_band(t_prog_state *state, int band, int chunk_size,
				int n)
{
	int	min;
	int	max;
	int	width;

	min = band * chunk_size;
	max = min + chunk_size;
	if (max > n)
		max = n;
	width = max - min;
	pull_band_elements(state, min, max, width);
}

/*

*/
static void	pull_band_elements(t_prog_state *state, int min,
				int max, int width)
{
	int	pulled;
	int	rev;
	int	val;

	pulled = 0;
	rev = 0;
	while (pulled < width && state->a->size > 0 && rev <= state->a->size)
	{
		val = state->a->top->rank;
		if (val >= min && val < max)
		{
			op_pb(state);
			pulled++;
			rev = 0;
		}
		else
		{
			op_ra(state);
			rev++;
		}
	}
}
