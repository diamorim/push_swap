#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_program_state	*prog_state;

	if (argc == 1)
		return (0);
	prog_state = malloc(sizeof(t_prog_state));
	if (!prog_state)
	{
		write(2, "Error\n", 6);
		return (1);
	}
//	init_prog_state(prog_state);
//	run_prog_state(prog_state, argc, argv);
	return (0);
}
