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

void	smart_double_rotate(t_stack *a, t_stack *b, t_node *targ_a, t_node *targ_b)
{
	int	pos_a;
	int	pos_b;

	while (a->top != targ_a && b->top != targ_b)
		{
			pos_a = get_pos_node(a, targ_a);
			pos_b = get_pos_node(b, targ_b);
			if (pos_a <= a->size/2 && pos_b <= b->size/2)
			{
				rr(a, b)
			}
			else if (pos_a > a->size/2 && pos_b > b->sixe/2)
			{
				rrr(a, b);
			}
			else
				break ;
		}
}

void	push_node(t_stack *a, t_stack *b, int start, int end)
{
	t_node	*target;

	target = find_target_node(a, start, end);
	while (target)
	{
		rotate_to_top(a, target, 'a');
		if (target->index < (start + end) / 2)
		{
			pb(b, a);
			rb(b);
		}
		else
			pb(b, a);
		target = find_target_node(a, start, end);
	}
}
