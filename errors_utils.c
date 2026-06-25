#include "push_swap.h"

int check_maxint(char **argv)
{
	//check if there's any argument
	if (!argv)
		return 0;
	//looping throught arguments and checking if they are between the maximum int and the minimum int
	while (*argv)
	{
		if (check_flags(*argv))
		{
			argv++;
			continue;
		}
		if (ft_strtol(*argv) > INT_MAX || ft_strtol(*argv) < INT_MIN)
			return 0;
		argv++;
	}
	return 1;
}
int reps_check(char **argv, int occ)
{
	int occurences;

	occurences = 0;
	while (*argv)
	{
		if (check_flags(*argv))
		{
			argv++;
			continue;
		}
		if (ft_atoi(*argv) == occ)
			occurences++;
		argv++;
	}
	return (occurences);
}
