/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaes <acaes@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 09:16:19 by acaes             #+#    #+#             */
/*   Updated: 2025/02/12 09:16:19 by acaes            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void	pushy(t_stack *dest, t_stack *src)
{
	t_node	*temp;

	if (!src || !src->top)
		return ;
	temp = src->top;
	src->top = src->top->next;
	temp->next = dest->top;
	dest->top = temp;
	src->size--;
	dest->size++;
}

void	pa(t_stack *a, t_stack *b)
{
	pushy(a, b);
	write(1, "pa\n", 3);
}

void	pb(t_stack *b, t_stack *a)
{
	pushy(b, a);
	write(1, "pb\n", 3);
}
