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
        curr = curr->next;
    }
}