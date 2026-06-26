#include <criterion/criterion.h>
#include "../../push_swap.h"

Test(ft_strtol, basic)
{
	char num[] = "2147483649";
	long nu = 2147483647L + 2;

	cr_assert_not(ft_strtol(NULL));
	cr_assert_not(ft_strtol(""));
	cr_expect_eq(ft_strtol(num), nu);
	nu = -21474836478L - 2;
	cr_expect_eq(ft_strtol("-21474836480"), nu);
}