/*
	I (Noah :-) would propose to put some of the utilities
	related to input here:
		- is_number.c()
		- ft_strol.c()
		- int check_errors()
		- int check_maxint()
		- int reps_check()

	This would tidy up files as well as main.c

	Are we allowed to put files in folders? I think we
	we are not :-(

*/
#include "push_swap.h"


#include "libft/libft.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}

int ft_isnumber(char *str)
{
	if (!str || !*str)
		return 0;
	if (*str == '-')
		str++;
	if (!*str)
		return 0;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return 0;
		str++;
	}
	return 1;
}


long	ft_strtol(char *str)
{
    long	result;
    int		sign;

    result = 0;
    sign = 1;
    if (!str)
        return 0;

    while (*str == ' ' || (*str >= 9 && *str <= 13))
        str++;
    if (*str == '-' || *str == '+')
    {
        if (*str == '-')
            sign = -1;
        str++;
    }
    while (*str >= '0' && *str <= '9')
    {
        result = result * 10 + (*str - '0');
        str++;
    }
    return (result * sign);
}
