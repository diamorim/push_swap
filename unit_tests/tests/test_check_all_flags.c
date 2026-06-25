#include <criterion/criterion.h>
#include "../../push_swap.h"

Test(check_all_flags, basic)
{
	char *str[] = {"--simple", "hola", "--medium", "nothing", NULL};
	char **nothing = NULL;

	cr_assert_not(check_allflags(nothing));
	cr_expect_eq(check_allflags(str), 2);
}