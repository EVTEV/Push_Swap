/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaes <acaes@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 23:40:31 by acaes             #+#    #+#             */
/*   Updated: 2025/02/24 23:40:31 by acaes            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	sort_two(t_stack *a)
{
	if (a->top->value > a->top->next->value)
		sa(a);
}

void	sort_three(t_stack *a)
{
	t_node	*max;

	max = get_max_node(a);
	if (a->top == max)
		ra(a);
	else if (a->top->next == max)
		rra(a);
	if (a->top->value > a->top->next->value)
		sa(a);
}

void	sort_four(t_stack *a, t_stack *b)
{
	t_node	*min;
	int		position;

	min = get_min_node(a);
	position = get_node_position(a, min);
	if (position <= 2)
	{
		while (a->top != min)
			ra(a);
	}
	else
	{
		while (a->top != min)
			rra(a);
	}
	pb(b, a);
	sort_three(a);
	pa(a, b);
}

void	sort_five(t_stack *a, t_stack *b)
{
	t_node	*m;
	int		p;
	int		i;

	i = 0;
	while (i < 2)
	{
		m = get_min_node(a);
		p = get_node_position(a, m);
		if (p <= (a->size / 2))
			while (a->top != m)
				ra(a);
		else
			while (a->top != m)
				rra(a);
		pb(b, a);
		i++;
	}
	sort_three(a);
	pa(a, b);
	pa(a, b);
}
