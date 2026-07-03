#include "../push_swap.h"

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