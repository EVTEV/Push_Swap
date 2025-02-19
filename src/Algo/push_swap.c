/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaes <acaes@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 09:16:08 by acaes             #+#    #+#             */
/*   Updated: 2025/02/12 09:16:08 by acaes            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	sort_small(t_stack *a, t_stack *b)
{
	if (a->size == 2)
		sort_two(a);
	else if (a->size == 3)
		sort_three(a);
	else if (a->size == 4)
		sort_four(a, b);
	else if (a->size == 5)
		sort_five(a, b);
}

void	sort_chunk(t_stack *a, t_stack *b)
{
	int	chunk_size;
	int	chunk_start;
	int	i;
	int	total_chunks;

	chunk_size = get_chunk_size(a->size);
	total_chunks = (a->size + chunk_size - 1) / chunk_size;
	i = 0;
	while (i < total_chunks)
	{
		chunk_start = i * chunk_size;
		process_chunk(a, b, chunk_start,
			chunk_start + chunk_size - 1);
		i++;
	}
	while (b->size > 0)
	{
		move_to_top(b, get_max_node(b));
		pa(a, b);
	}
}

void	push_swap(t_stack *a, t_stack *b)
{
	if (!is_sorted(a))
	{
		if (!a || !a->top || a->size <= 1)
			return ;
		if (a->size <= 5)
			sort_small(a, b);
		else
			sort_chunk(a, b);
	}
}
