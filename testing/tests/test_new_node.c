#include <criterion/criterion.h>
#include "../../push_swap.h"

Test(new_node, basic)
{
	t_node *node = new_node(4);

	cr_assert(node != NULL);
	cr_expect_eq(node->value, 4, "the result is: %d and the expected result is: %d", 4);
	cr_expect(node->next == NULL);
	cr_expect(node->prev == NULL);
}