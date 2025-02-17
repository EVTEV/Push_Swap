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
}
 
void	sort_chunk(t_stack *a, t_stack *b)
{
	int	chunk_size;
	int	current_chunk;

	chunk_size = get_chunk_size(a->size);
	current_chunk = 0;
	while (current_chunk * chunk_size < a->size)
    {
		push_chunk_to_b(a, b, current_chunk, chunk_size);
		current_chunk++;
    }
	while (b->size > 0)
		push_max_to_a(a, b);
}

void	push_swap(t_stack *a, t_stack *b) 
{
    if (!is_sorted(a)) 
	{
        if (!a || !a->top || a->size <= 1)
            return ;
        if (a->size == 2)
            sa(a);
        else if (a->size == 3)
            sort_three(a);
        else
            sort_stack(a, b);
    }
}
