#include <criterion/criterion.h>
#include "../../push_swap.h"

Test(reps_check, basic)
{
	char *str[] = {"1234", "2", "1234", NULL};
	char *str2[] = {"1234", "2", NULL};

	cr_assert_not(reps_check(NULL, 1));
	cr_expect_eq(reps_check(str, 1234), 2);
	cr_expect_eq(reps_check(str2, 1234), 1);
}