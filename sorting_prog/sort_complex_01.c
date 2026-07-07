#include "../push_swap.h"

void	rank(t_prog_state *state);
int		count_bits(int n);
void	push_all_a(t_prog_state *state);

void	sort_complex(t_prog_state *state)
{
	int	stack_size;
	int	bit;
	int	biggest_bit;
	int	i;

	rank(state);
	stack_size = state->a->size;
	bit = 0;
	i = 0;
	biggest_bit = count_bits(stack_size - 1);
	while (bit < biggest_bit)
	{
		while (i < stack_size)
		{
			if ((state->a->top->rank >> bit) & 1)
				op_ra(state);
			else
				op_pb(state);
			i++;
		}
		i = 0;
		push_all_a(state);
		bit++;
	}
}

void	rank(t_prog_state *state)
{
	int 	*arr;
	t_node	*current_node;
	int		i;

	if (!state || !state->a || state->a->size == 0 || !state->a->top)
		return ;
	i = 0;
	arr = stack_to_arr(state->a);
	quick_sort(arr, 0, state->a->size - 1);
	current_node = state->a->top;
	while (i < state->a->size)
	{
		current_node->rank = binary_search(arr, state->a->size, current_node->value);
		current_node = current_node->next;
		i++;
	}
	free(arr);
}

int	count_bits(int n)
{
	int bits;

	bits = 0;
	while (n > 0)
	{
		n = n >> 1;
		bits++;
	}
	return bits;
}

void	push_all_a(t_prog_state *state)
{
	int i;
	int	target;

	target = state->b->size;
	i = 0;
	while (i < target)
	{
		op_pa(state);
		i++;
	}
}
