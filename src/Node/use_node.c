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

int	get_node_position(t_stack *stack, t_node *target)
{
	t_node	*current;
	int		pos;

	current = stack->top;
	pos = 0;
	while (current && current != target)
	{
		pos++;
		current = current->next;
	}
	return (pos);
}

void	move_to_top(t_stack *stack, t_node *target)
{
	int	pos;
	int	middle;

	pos = get_node_position(stack, target);
	middle = stack->size / 2;
	if (pos <= middle)
	{
		while (pos > 0)
		{
			ra(stack);
			pos--;
		}
	}
	else
	{
		while (pos < stack->size)
		{
			rra(stack);
			pos++;
		}
	}
}
