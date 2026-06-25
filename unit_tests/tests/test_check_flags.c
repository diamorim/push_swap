#include <criterion/criterion.h>
#include "../../push_swap.h"

Test(checkflag, basic)
{
	cr_expect(check_flags("--simple"));
	cr_expect(check_flags("--medium"));
	cr_expect(check_flags("--adaptive"));
	cr_expect(check_flags("--complex"));
	cr_expect_not(check_flags("--comple"));
	cr_expect_not(check_flags("--complexi"));
}