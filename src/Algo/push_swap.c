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

static void	sort_chunk(t_stack *a, t_stack *b)
{
	int	chunk_size;
	int	current_chunk;
	int	target_max;
	int	pushed;

	chunk_size = get_chunk_size(a->size);
	current_chunk = 0;
    while (a->size > 3) 
	{
		target_max = (current_chunk + 1) * chunk_size;
		pushed = 0;
		while (pushed < chunk_size && a->size > 3) 
		{
			if (a->top->index <= target_max) 
			{
				pb(b, a);
				pushed++;
			}
			else
                ra(a);
        }
		current_chunk++;
	}
	sort_three(a);
}

static void	merge_stack(t_stack *a, t_stack *b) 
{
	t_node	*best_move;

   	while (b->size) 
	{
        best_move = find_best_node(a, b);
        execute_move(a, b, best_move);
    }    
    align_stack(a);
}

void	sort_stack(t_stack *a, t_stack *b)
{
	sort_chunk(a, b);
    merge_stack(a, b);
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
			sort_stack(a, b);
	}
}
