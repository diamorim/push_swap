#include "../test.h"

Test(partition, basic)
{
	int	arr[] = {5, 3, 8, 1, 9, 2};
	int	expected[] = {1, 2, 8, 5, 9, 3};
	int	pivot_index;

	pivot_index = partition(arr, 0, 5);

	cr_expect_eq(pivot_index, 1, "expected pivot index 1 but got %d", pivot_index);
	expect_arr(arr, expected, 6);
}

Test(partition, single_element)
{
	int	arr[] = {42};
	int	pivot_index;

	pivot_index = partition(arr, 0, 0);

	cr_expect_eq(pivot_index, 0, "expected pivot index 0 but got %d", pivot_index);
	cr_expect_eq(arr[0], 42);
}

Test(quick_sort, basic)
{
	int	arr[] = {5, 3, 8, 1, 9, 2};
	int	expected[] = {1, 2, 3, 5, 8, 9};

	quick_sort(arr, 0, 5);

	expect_arr(arr, expected, 6);
}

Test(quick_sort, with_negatives_and_duplicates)
{
	int	arr[] = {-4, 10, -4, 0, 7, -1, 10};
	int	expected[] = {-4, -4, -1, 0, 7, 10, 10};

	quick_sort(arr, 0, 6);

	expect_arr(arr, expected, 7);
}

Test(quick_sort, already_sorted)
{
	int	arr[] = {1, 2, 3, 4, 5};
	int	expected[] = {1, 2, 3, 4, 5};

	quick_sort(arr, 0, 4);

	expect_arr(arr, expected, 5);
}

Test(quick_sort, single_element)
{
	int	arr[] = {7};
	int	expected[] = {7};

	quick_sort(arr, 0, 0);

	expect_arr(arr, expected, 1);
}