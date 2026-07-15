/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_01.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damorim- <damorim-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 13:43:55 by diamo             #+#    #+#             */
/*   Updated: 2026/07/15 18:26:30 by damorim-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*new_node(int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->rank = -1;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	stack_add_front(t_stack *stack, t_node *new)
{
	if (!stack || !new)
		return ;
	if (!stack->top)
	{
		stack->top = new;
		change_next_prev(new, new, new);
	}
	else
	{
		if (stack->size == 1)
		{
			change_next_prev(stack->top, new, new);
			change_next_prev(new, stack->top, stack->top);
		}
		else
		{
			change_next_prev(new, stack->top->prev, stack->top);
			stack->top->prev->next = new;
			stack->top->prev = new;
		}
		stack->top = new;
	}
	stack->size++;
}

/*	_____ stack_add_back() _____
//	This function receives a pointer
//	to a stack as well as a node
//	and adds the node to the back of
//	the stack.
*/
void	stack_add_back(t_stack *stack, t_node *new)
{
	t_node	*last;

	if (!stack || !new)
		return ;
	if (!stack->top)
	{
		stack->top = new;
		change_next_prev(new, new, new);
	}
	else
	{
		last = stack->top->prev;
		if (last == stack->top)
		{
			change_next_prev(new, stack->top, stack->top);
			change_next_prev(stack->top, new, new);
		}
		else
		{
			stack->top->prev->next = new;
			change_next_prev(new, stack->top->prev, stack->top);
			stack->top->prev = new;
		}
	}
	stack->size++;
}

t_node	*stack_last_node(t_stack *stack)
{
	if (!stack || !stack->top)
		return (NULL);
	return (stack->top->prev);
}

void	change_next_prev(t_node *node, t_node *new_prev, t_node *new_next)
{
	if (!node || !new_next || !new_prev)
		return ;
	node->next = new_next;
	node->prev = new_prev;
}
