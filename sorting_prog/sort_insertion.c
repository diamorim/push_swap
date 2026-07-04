#include "../push_swap.h"

static int	count_less(t_stack *s, int value);

void	sort_insertion(t_prog_state *state)
{
	int	rank;
	int	min_pos;
	int	target;

	if (!state || !state->a || state->a->size <= 1)
		return ;
	if (handle_small_sort(state))
		return ;
	while (state->a->size > 3)
		op_pb(state);
	sort_3(state);
	while (state->b->size > 0)
	{
		rank = count_less(state->a, state->b->top->value);
		min_pos = find_pos_min(state->a);
		target = (min_pos + rank) % state->a->size;
		smart_rotate(state, state->a, target);
		op_pa(state);
	}
	smart_rotate(state, state->a, find_pos_min(state->a));
}

static int	count_less(t_stack *s, int value)
{
	t_node	*node;
	int		i;
	int		cnt;

	if (!s || s->size == 0)
		return (0);
	node = s->top;
	i = 0;
	cnt = 0;
	while (i < s->size)
	{
		if (node->value < value)
			cnt++;
		node = node->next;
		i++;
	}
	return (cnt);
}
