#include "../test.h"

Test(binary_search, finds_every_index)
{
	int	arr[] = {1, 2, 3, 4, 5};

	cr_expect_eq(binary_search(arr, 5, 1), 0, "value 1 should be at index 0 and it's returning index %d", binary_search(arr, 5, 1));
	cr_expect_eq(binary_search(arr, 5, 2), 1, "value 2 should be at index 1 and it's returning index %d", binary_search(arr, 5, 2));
	cr_expect_eq(binary_search(arr, 5, 3), 2, "value 3 should be at index 2 and it's returning index %d", binary_search(arr, 5, 3));
	cr_expect_eq(binary_search(arr, 5, 4), 3, "value 4 should be at index 3 and it's returning index %d", binary_search(arr, 5, 4));
	cr_expect_eq(binary_search(arr, 5, 5), 4, "value 5 should be at index 4 and it's returning index %d", binary_search(arr, 5, 5));
}

Test(binary_search, single_element)
{
	int	arr[] = {9};

	cr_expect_eq(binary_search(arr, 1, 9), 0);
}

Test(binary_search, null_array)
{
	cr_expect_eq(binary_search(NULL, 5, 1), -1);
}