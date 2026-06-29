#include <criterion/criterion.h>
#include "../../push_swap.h"

Test(init_stack, basic)
{
	t_stack *stack = init_stack();

	cr_assert(stack != NULL);
	cr_assert(stack->top == NULL);
	cr_expect(stack->size == 0);
}