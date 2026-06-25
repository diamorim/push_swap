#include <criterion/criterion.h>
#include "../../push_swap.h"

Test(checkflag, basic)
{
	cr_assert_eq(check_flags("simple--"), 1);
	cr_assert_eq(check_flags("medium--"), 1);
	cr_assert_eq(check_flags("adaptive--"), 1);
	cr_assert_eq(check_flags("complex--"), 1);
	cr_assert_eq(check_flags("--comple"), 0);
	cr_assert_eq(check_flags("complex--\0"), 0);
}