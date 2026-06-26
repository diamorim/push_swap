#include "../push_swap.h"

int check_errors(int argc, char **argv)
{
	int i;

	if (!argv || argc < 2)
		return 0;

	i = 0;
	argv++;
	if (check_allflags(argv) > 1)
		return 0;

	while (argv[i])
	{
		if (check_flags(argv[i]))
		{
			i++;
			continue;
		}
		if (!ft_isnumber(argv[i]))
			return 0;
		i++;
	}
	i = 0;
	if (!check_maxint(argv))
		return 0;
	while (argv[i])
	{
		if (check_flags(argv[i]))
		{
			i++;
			continue;
		}
		if (reps_check(argv, ft_atoi(argv[i])) > 1)
			return 0;
		i++;
	}
	return 1;
}

int check_maxint(char **argv)
{
	if (!argv)
		return 0;
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

	if (!argv)
		return 0;

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


int	check_flags(char *str)
{
	if (!str)
		return 0;
	if (ft_strncmp(str, "--simple", 9) == 0
		|| ft_strncmp(str, "--medium", 9) == 0
	 	|| ft_strncmp(str, "--adaptive", 11) == 0
		|| ft_strncmp(str, "--complex", 10) == 0)
		return 1;
	return 0;
}



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
