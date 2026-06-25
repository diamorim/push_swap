#include <criterion/criterion.h>
#include "../../push_swap.h"

Test(maxint, basic)
{
	char *str[] = {"hello", "1236", "21352613561253", NULL};
	char *str2[] = {"hello", "1236", NULL};

	cr_assert_not(check_maxint(NULL));
	cr_expect_not(check_maxint(str));
	cr_expect(check_maxint(str2));
}