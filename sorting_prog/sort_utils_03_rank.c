#include "../push_swap.h"
//
// ____ rank() ____
//
// Function inherits a stack (via state) and
// create and migrates the values to an array.
//
// Next it sorts the values in the array using
// quick_sort.
//
// Then, the function assigns inside of the stack a rank
// for each of the values stored in array/stack using binary
// search inside of the array.
//
// Lastly, the function frees up memory allocated to the array
// as it is no longer needed.
//
void	rank(t_prog_state *state)
{
	int 	*arr;
	t_node	*current_node;
	int		i;

	if (!state || !state->a || state->a->size == 0 || !state->a->top)
		return;
	i = 0;
	arr = stack_to_arr(state->a);
	if (!arr)
		return;
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

//
// ____ stack_to_arr() ____
//
// Function creates and allocates memory for an
// array and populates the array based on values
// from a given stack.
//
// Function loops through the entire stack from
// beginning to end and returns the array, `arr`
// to the caller.
//

int	*stack_to_arr(t_stack *stack)
{
	int	i;
	int	*arr;
	t_node *current_node;

	if (!stack || !stack->size || !stack->top)
		return (NULL);
	i = 0;
	arr = malloc(stack->size * sizeof(*arr));
	if (!arr)
		return (NULL);

	current_node = stack->top;

	while (i < stack->size)
	{
		arr[i] = current_node->value;
		current_node = current_node->next;
		i++;
	}
	return (arr);
}

//
// ____ quick_sort ____
// Function sorts an array ---> the very first time, and
// only time, the low is `0` and the high is the `size - 1`.
//
// The partition, as we will see in the partition() function
// is always set to 'high' for whichever section is being
// sorted.
//
//
void	quick_sort(int arr[], int low, int high)
{
	int	pivot_idx;

	if (!arr)
		return;

	if (low < high)
	{
		pivot_idx = partition(arr, low, high);
		quick_sort(arr, low, pivot_idx - 1);
		quick_sort(arr, pivot_idx + 1, high);
	}
}

int		partition(int arr[], int low, int high)
{
	int	i;
	int	j;
	int	pivot;

	if (!arr)
		return -1;

	i = low - 1;
	j = low;
	pivot = arr[high];

	while (j < high)
	{
		if (arr[j] < pivot)
		{
			i++;
			ft_swop(&arr[i], &arr[j]);
		}
		j++;
	}
	ft_swop(&arr[i + 1], &arr[high]);
	return (i + 1);
}


// ____ binary_search() ____
// Use of this function assumes that the array it
// is searching through is presorted.
//
// Function assigns an index, 'mid', which begins initially
// between the beginning ('0') & end ('n') positions of the array.
//
// If the arr[mid] == target, function returns that position,
// mid.
//
// If arr[mid] < target, then process repeats at the second half
// of the array.
//
// If arr[mid] > target, then process repeats in the first half
// of the array.
//
// Function continues to loop through a divide-and-conquer strategy
// until, ultimatealy, it finds the target, at which point:
// arr[mid] == target.
//
int		binary_search(int arr[], int n, int target)
{
	int	low;
	int	high;
	int	mid;

	if (!arr)
		return (-1);

	low = 0;
	high = n-1;
	while (low < high)
	{
		mid = low + (high - low) / 2;
		if (arr[mid] == target)
			return (mid);
		if (arr[mid] < target)
			low = mid + 1;
		else
			high = mid - 1;
	}
	return (low);
}
