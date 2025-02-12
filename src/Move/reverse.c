/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaes <acaes@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 09:16:29 by acaes             #+#    #+#             */
/*   Updated: 2025/02/12 09:16:29 by acaes            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	reverse(t_stack *stack)
{
	t_node	*last;
	t_node	*temp;

	if (!stack || !stack->top || !stack->top->next)
		return ;
	last = stack->top;
	temp = NULL;
	while (last->next)
	{
		temp = last;
		last = last->next;
	}
	temp->next = NULL;
	last->next = stack->top;
	stack->top = last;
}

void	rra(t_stack *a)
{
	reverse(a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack *b)
{
	reverse(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack *a, t_stack *b)
{
	reverse(a);
	reverse(b);
	write(1, "rrr\n", 4);
}
