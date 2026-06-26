#include "push_swap.h"

int	check_allflags(char **argv)
{
	int flags_amm;

	flags_amm = 0;
	if (!argv)
		return 0;
	while (*argv)
	{
		if (ft_strncmp(*argv, "--simple", 9) == 0 
			|| ft_strncmp(*argv, "--medium", 9) == 0
			 || ft_strncmp(*argv, "--adaptive", 11) == 0
			|| ft_strncmp(*argv, "--complex", 10) == 0)
			flags_amm++;
		argv++;
	}
	
	return flags_amm;
}