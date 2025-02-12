/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaes <acaes@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 09:17:31 by acaes             #+#    #+#             */
/*   Updated: 2025/02/12 09:17:31 by acaes            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

t_stack	*init_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->top = NULL;
	stack->size = 0;
	return (stack);
}

void	fill_stack(t_stack *stack, int value)
{
	t_node	*new;
	t_node	*current;

	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
		return ;
	new->value = value;
	new->next = NULL;
	if (!stack->top)
		stack->top = new;
	else
	{
		current = stack->top;
		while (current->next)
			current = current->next;
		current->next = new;
	}
	stack->size++;
}

void	free_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*next;

	current = stack->top;
	while (current)
	{
		next = current->next;
		free(current);
		current = NULL;
		current = next;
	}
	free(stack);
}
