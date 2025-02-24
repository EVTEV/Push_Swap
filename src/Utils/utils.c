/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaes <acaes@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 09:17:40 by acaes             #+#    #+#             */
/*   Updated: 2025/02/12 09:17:40 by acaes            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	get_chunk_size(int size)
{
	if (size <= 4)
		return (1);
	else if (size <= 50)
		return (4);
	else if (size <= 100)
		return (6);
	else if (size <= 250)
		return (8);
	else if (size <= 500)
		return (12);
	return (15);
}

int	is_sorted(t_stack *stack)
{
	t_node	*current;

	if (!stack || !stack->top || stack->size <= 1)
		return (1);
	current = stack->top;
	while (current && current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

void	align_stack(t_stack *a)
{
	t_node	*min;
	int		min_pos;
	int		rotation;

	min = get_min_node(a);
	min_pos = get_node_position(a, min);
	if (min_pos > a->size / 2)
		rotation = a->size - min_pos;
	else
		rotation = min_pos;
	while (rotation--)
	{
		if (min_pos > a->size / 2)
			rra(a);
		else
			ra(a);
	}
}

void	msg_error(t_stack *a, t_stack *b)
{
	write(2, "Error\n", 6);
	if (a)
		free_stack(a);
	if (b)
		free_stack(b);
	exit(1);
}
