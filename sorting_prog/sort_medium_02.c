#include "../push_swap.h"

static void	extract_values(t_stack *s, int *vals);
static void	assign_ranks(t_stack *s, int *vals);

/*
	rank_stack() extracts the values from
	inside a given stack and stores them inside
	an array ... via extract_values()

	Next, we assign the corresponding
	sorting rank of the value back inside of
	the stack.
*/

void	rank_stack(t_stack *s)
{
	int	*vals;

	if (!s || s->size == 0 || !s->top)
		return ;
	vals = malloc(sizeof(int) * s->size);
	if (!vals)
		return ;
	extract_values(s, vals);
	assign_ranks(s, vals);
	free(vals);
}

/*
	This function simply extracts the values inside
	the stack and assigns the value into an array of
	integers.

	We use an array as we can avoid complexities
	& inefficiencies related to pointers,
	& memory management.
*/

static void	extract_values(t_stack *s, int *vals)
{
	t_node	*curr;
	int		i;

	curr = s->top;
	i = 0;
	while (i < s->size)
	{
		vals[i] = curr->value;
		curr = curr->next;
		i++;
	}
}

/*
	We use two nested loops here:
		i - cycles through the outer loop --
			it goes through the entire stack
			once

		j	cycles through the inner loop --
			it runs through the entire stack each
			time

			Within the inner loop, the code
			calculates the rank  by counting smaller elements.

		Once the inner loop finishes, the outer loop asssigns
		the total rank to the stack node at curr->rank.

		Imagine we have 100 elements in a stack:
		- i would run through the stack 100 times; and then for each step
		- j would run 100 comparisons to find the rank

		- the total number of iterations would be 10,000

*/
static void	assign_ranks(t_stack *s, int *vals)
{
	t_node	*curr;
	int		i;
	int		j;
	int		rank;

	curr = s->top;
	i = 0;
	while (i < s->size)
	{
		rank = 0;
		j = 0;
		while (j < s->size)
		{
			if (vals[j] < vals[i])
				rank++;
			j++;
		}
		curr->rank = rank;
		curr = curr->next;
		i++;
	}
}
