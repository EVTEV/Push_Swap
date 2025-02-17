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



