/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaes <acaes@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 09:16:59 by acaes             #+#    #+#             */
/*   Updated: 2025/02/12 09:16:59 by acaes            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

t_node	*get_max_node(t_stack *stack)
{
	t_node	*current;
	t_node	*max;

	if (!stack || !stack->top)
		return (NULL);
	current = stack->top;
	max = current;
	while (current)
	{
		if (current->value > max->value)
			max = current;
		current = current->next;
	}
	return (max);
}

t_node	*get_min_node(t_stack *stack)
{
	t_node	*current;
	t_node	*min;

	if (!stack || !stack->top)
		return (NULL);
	current = stack->top;
	min = current;
	while (current)
	{
		if (current->value < min->value)
			min = current;
		current = current->next;
	}
	return (min);
}


