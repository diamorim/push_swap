#include "test.h"

void expect_stack(t_stack *stack, int expected[], int size)
{
    cr_expect_eq(stack->size, size, "expected %d but got %d in stack size", size, stack->size);

    t_node *curr = stack->top;

    for (int i = 0; i < size; i++)
    {
		cr_assert(curr->next != NULL);
		cr_assert(curr->prev != NULL);
        cr_expect_eq(curr->value, expected[i], "expected %d but got %d in index %d", expected[i], curr->value, i);
    int next = (i + 1) % size;
    int prev = (i - 1 + size) % size;

    cr_expect_eq(curr->next->value,
        expected[next],
        "expected %d but got %d in index %d",
        expected[next], curr->next->value, next);

    cr_expect_eq(curr->prev->value,
        expected[prev],
        "expected %d but got %d in index %d",
        expected[prev], curr->prev->value, prev);
            
        curr = curr->next;
    }
}

void expect_arr(int arr[], int expected[], int size)
{
    for (int i = 0; i < size; i++)
        cr_expect_eq(arr[i], expected[i], "expected: %d   result: %d", expected[i], arr[i]);
}
