#include <criterion/criterion.h>
#include "../../push_swap.h"
#include "../../libft/libft.h"

Test(ft_isnumber, basic)
{
	cr_assert_not(ft_isnumber(NULL));
	cr_assert_not(ft_isnumber(""));
	
	cr_expect(ft_isnumber("0"));
	cr_expect(ft_isnumber("9"));
	cr_expect(ft_isnumber("2147483647"));
	cr_expect(ft_isnumber("-21474836478"));
	cr_expect_not(ft_isnumber("/"));
	cr_expect_not(ft_isnumber(":"));
	
}