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

t_node	*find_node_by_value(t_stack *stack, int value)
{
    t_node	*current = stack->top;

	current = stack->top;
    while (current)
	{
        if (current->value == value)
            return current;
        current = current->next;
    }
    return (NULL);
}

