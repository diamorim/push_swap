
/*
	__sort_simple.c__ includes:
		- sort_simple()
		- handle_small_sort()
		- sort_3()

	The purpose of these functions is to sort a stack
	with worst case efficiency of O(n^2) as chosen by
	the user or the adaptive algorithm based on the disorder
	metric (decided per adaptive algorithm).
*/

void	sort_simple(t_ps *ps)
{
	if (handle_small_sort(ps))
		return ;
	while (ps->a->size > 3)
	{
		rotate_cheapest(ps, ps->a, find_min_position(ps->a), 1);
		do_op(ps, "pb");
	}
	sort_3(ps);
	while (ps->b->size > 0)
		do_op(ps, "pa");
}


/*
	Handle stacks of size 0–3 so algorithm entry points stay DRY.
	Returns 1 if the caller should return immediately (small stack fully
	sorted), 0 if the caller should proceed with its main algorithm.
	Size 2: swaps only if the top element is greater than the second.
*/
int	handle_small_sort(t_ps *ps)
{
	if (ps->a->size <= 1)
		return (1);
	if (ps->a->size == 2)
	{
		if (ps->a->top->value > ps->a->top->next->value)
			do_op(ps, "sa");
		return (1);
	}
	if (ps->a->size == 3)
	{
		sort_3(ps);
		return (1);
	}
	return (0);
}



/*
	Sort exactly 3 elements in stack A in at most 2 operations.
	Precondition: ps->a->size == 3 (caller must guard smaller sizes).
	Reads values as a=top, b=middle, c=bottom.
	Hardcodes all 5 unsorted permutations with known-optimal sequences.
*/
void	sort_3(t_ps *ps)
{
	int	a;
	int	b;
	int	c;

	a = ps->a->top->value;
	b = ps->a->top->next->value;
	c = ps->a->top->prev->value;
	if (a > b && a > c)
	{
		if (b > c)
		{
			do_op(ps, "sa");
			do_op(ps, "rra");
		}
		else
			do_op(ps, "ra");
	}
	else if (a > b)
		do_op(ps, "sa");
	else if (b > c)
	{
		if (a > c)
			do_op(ps, "rra");
		else
		{
			do_op(ps, "sa");
			do_op(ps, "ra");
		}
	}
}
