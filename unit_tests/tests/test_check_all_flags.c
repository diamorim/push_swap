#include <criterion/criterion.h>
#include "../../push_swap.h"

Test(check_all_flags, basic)
{
	char *str[] = {"--simple", "hola", "--medium", NULL};
	char *argv2[] = {"--medium" ,"--adaptive", "--complex", "7", "--simple", NULL};
	char **nothing = NULL;

	cr_assert_not(check_allflags(nothing));
	cr_expect_eq(check_allflags(str), 2);
	cr_expect_eq(check_allflags(argv2), 4);
}