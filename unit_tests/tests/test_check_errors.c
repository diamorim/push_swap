#include <criterion/criterion.h>
#include "../../push_swap.h"

Test(check_errors, basic)
{
	char *argv[] = {"argv"};
	char *argv0[] = {"input" ,"--simple", "1234", "-1234", "7", NULL};
	char *argv1[] = {"input", "1234", "-1234", "7", "--simple", NULL};
	char *argv2[] = {"input" ,"--medium" ,"1234", "-1234", "7", "--simple", NULL};
	char *argv3[] = {"input" ,"1234", "-1234", "7", "--simple", "7", NULL};
	char *argv4[] = {"input" ,"1234", "-1234", "7", "--simple", "21321212321321", NULL};

	cr_assert_not(check_errors(0 ,NULL));
	cr_expect(check_errors(4 ,argv0));
	cr_expect_not(check_errors(1 ,argv));
	cr_expect(check_errors(4 ,argv1));
	cr_expect_not(check_errors(5 ,argv2));
	cr_expect_not(check_errors(5 ,argv3));
	cr_expect_not(check_errors(5 ,argv4));
}