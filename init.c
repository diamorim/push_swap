#include "push_swap.h"

t_stack	*init_stack(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->top = NULL;
	stack->size = 0;
	return (stack);
}

t_prog_state	*init_prog_state(void)
{
	t_prog_state	*state;
	int				i;

	state = malloc(sizeof(t_prog_state));
	if (!state)
		return (NULL);
	state->a = init_stack();
	state->b = init_stack();
	if (!state->a || !state->b)
	{
		if (state->a)
			free(state->a);
		if (state->b)
			free(state->b);
		free(state);
		return (NULL);
	}
	state->n = 0;
	state->ops_count_total = 0;
	i = 0;
	while (i < OP_TYPES_TOTAL)
		state->ops_count_per_type[i++] = 0;
	state->strat_req = ADAPTIVE;
	state->strat_used = ADAPTIVE;
	state->bench = 0;
	state->disorder = 0.0;
	return (state);
}

void	free_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*next;

	if (!stack)
		return ;
	current = stack->top;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	free(stack);
}

void	free_prog_state(t_prog_state *state)
{
	if (!state)
		return ;
	if (state->a)
		free_stack(state->a);
	if (state->b)
		free_stack(state->b);
	free(state);
}
