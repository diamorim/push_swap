#include "../push_swap.h"

int		partition(int arr[], int low, int high)
{
	int	i;
	int	j;
	int	pivot;

	i = low - 1;
	j = 0;
	pivot = arr[high];

	while (j < high)
	{
		if (arr[j] < pivot)
		{
			i++;
			swop(arr[i], arr[j]);	
		}
		j++;
	}
	swop(arr[i + 1], pivot);
	return i + 1;
}
void	quick_sort(int arr[], int low, int high)
{
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
	return 0;
}
void	rank(t_prog_state *state)
{
	int 	*arr;
	t_node	*current_node;
	int		i;

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
	rank(state);
}
