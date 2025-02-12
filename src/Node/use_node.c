/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   use_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaes <acaes@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 09:17:07 by acaes             #+#    #+#             */
/*   Updated: 2025/02/12 09:17:07 by acaes            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	move_to_top(t_stack *stack, t_node *target)
{
	t_node	*current;
	int		pos;

	pos = 0;
	current = stack->top;
	while (current != target)
	{
		pos++;
		current = current->next;
	}
	if (pos <= stack->size / 2)
	{
		while (stack->top != target)
			rotate(stack);
	}
	else
	{
		while (stack->top != target)
			reverse(stack);
	}
}

void	rotate_to_top(t_stack *stack, t_node *target, char name)
{
	int	pos;
	int	mid;

	pos = get_pos_node(stack, target);
	mid = stack->size / 2;
	if (pos <= mid)
	{
		while (stack->top != target)
		{
			if (name == 'a')
				ra(stack);
			else
				rb(stack);
		}
	}
	else
	{
		while (stack->top != target)
		{
			if (name == 'a')
				rra(stack);
			else
				rrb(stack);
		}
	}
}

void	push_node(t_stack *a, t_stack *b, int start, int end)
{
	t_node	*target;

	target = find_target_node(a, start, end);
	while (target)
	{
		rotate_to_top(a, target, 'a');
		pb(b, a);
		target = find_target_node(a, start, end);
	}
}
