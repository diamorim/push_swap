#include "../push_swap.h"

int		partition(int arr[], int low, int high)
{
	int	i;
	int	j;
	int	pivot;

	if (!arr)
		return -1;
	
	i = low - 1;
	j = 0;
	pivot = arr[high];

	while (j < high)
	{
		if (arr[j] < pivot)
		{
			i++;
			ft_swop(arr[i], arr[j]);
		}
		j++;
	}
	ft_swop(arr[i + 1], pivot);
	return i + 1;
}
void	quick_sort(int arr[], int low, int high)
{
	if (!arr)
		return ;
	
	if (low < high)
	{
		int	pi;

		pi = partition(arr, low, high);
		quick_sort(arr, low, pi - 1);
		quick_sort(arr, pi + 1, high);
	}
}
int		binary_search(int arr[], int n, int x)
{
	int	low;
	int	high;
	
	if (!arr)
		return -1;
	
	low = 0;
	high = n-1;
	while (low < high)
	{
		int	mid;

		mid = low + (high - low) / 2;
		if (x == arr[mid])
			return mid;
		if (arr[mid] < x)
			low = mid + 1;
		else
			high = mid - 1;
	}
	return low;
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
	quick_sort(arr, 0, state->a->size);
	current_node = state->a->top;
	while (i < state->a->size)
	{
		current_node->rank = binary_search(arr, state->a->size, current_node->value);
		current_node = current_node->next;
		i++;
	}
	
}
void	radix_sort(t_prog_state *state)
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
