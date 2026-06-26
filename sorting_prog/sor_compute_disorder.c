#include "../push_swap.h"

/*
	__ compute_disorder.c_ contiains:
		- computer_disorder()
		- check_node()

	- compute_disorder() will be used by run_prog() in
		main.c.

	compute_disorder() exists to calculate "disorder"
	within a given stack.

	Disorder is really a misnomer.

	In the context of push_swap, "disorder" means that the numbers
	are not in perfectly ascending order (e.g. 1 2 3 4 5).

	Every time there a larger number precedes a smaller number,
	the amount of disorder increases.

	- 20%  disorder looks like [2 1 3 4 5]
	- 60%  disorder looks like [3 2 1 4 5]
	- 100% disorder looks like [5 4 3 2 1]

	Function looks into stack "a" and examines
	pair by pair of values in nodes to see if
	they are not in ascending order between them.

	If they are not in ascending order, the
	'mistakes' count increases by 1.

	__ NOTE __
	The computed disorder (% with two decimals).

	I researched whether it was better to use float or
	 double and. in theory, "double" is the standard.

	We will need to see how to output the data with
	the ft_printf() -- or maybe we need to create a modified
	version.
*/
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

/*
	__ IMPORTANT NOTE :-) __
	if the stack 's' doesn't exist or 's'
	has <2 members then there is "no
	disorder" and we can a return (0.0)
	as the disorder score.

	__ MAIN ACTION __
	Loop through the entire stack one node
	at a time until the end of the stack.

	We call 'check_node" (see above)

*/
