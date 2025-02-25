/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_cost.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaes <acaes@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 00:10:11 by acaes             #+#    #+#             */
/*   Updated: 2025/02/25 00:10:11 by acaes            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static int	abs_val(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static int	get_cost(t_stack *stack, t_node *node, int is_stack_a)
{
	int	pos;
	int	size;

	(void)is_stack_a;
	pos = get_node_position(stack, node);
	size = stack->size;
	if (pos > size / 2)
		return (-(size - pos));
	return (pos);
}

static t_cost	calculate_cost(t_stack *a, t_stack *b, t_node *node)
{
	t_cost	cost;
	t_node	*target;
	int		max_abs;

	target = find_target_position(a, node->value);
	cost.cost_b = get_cost(b, node, 0);
	cost.cost_a = get_cost(a, target, 1);
	if ((cost.cost_a > 0 && cost.cost_b > 0)
		|| (cost.cost_a < 0 && cost.cost_b < 0))
	{
		if (abs_val(cost.cost_a) > abs_val(cost.cost_b))
			max_abs = abs_val(cost.cost_a);
		else
			max_abs = abs_val(cost.cost_b);
		cost.total = max_abs;
	}
	else
		cost.total = abs_val(cost.cost_a) + abs_val(cost.cost_b);
	return (cost);
}

/*
t_node	*find_best_node(t_stack *a, t_stack *b)
{
	t_cost	cost;
	t_cost	best_cost;
	t_node	*current;
	t_node	*best_node;
	int		min_cost;

	current = b->top;
	best_node = NULL;
	min_cost = INT_MAX;
	while (current)
	{
		cost = calculate_cost(a, b, current);
		if (cost.total < min_cost)
		{
			min_cost = cost.total;
			best_node = current;
		}
		else if (cost.total == min_cost)
		{
			best_cost = calculate_cost(a, b, best_node);
			if (abs_val(cost.cost_a) + abs_val(cost.cost_b)
				< abs_val(best_cost.cost_a) + abs_val(best_cost.cost_b))
				best_node = current;
		}
		current = current->next;
	}
	return (best_node);
}*/

static t_node	*compare_best(t_context *context, t_node *current)
{
	t_cost	cost;
	t_cost	best_cost;

	cost = calculate_cost(context->a, context->b, current);
	if (cost.total < context->min_cost)
	{
		context->min_cost = cost.total;
		return (current);
	}
	if (cost.total == context->min_cost)
	{
		best_cost = calculate_cost(context->a, context->b, context->best_node);
		if (abs_val(cost.cost_a) + abs_val(cost.cost_b)
			< abs_val(best_cost.cost_a) + abs_val(best_cost.cost_b))
			return (current);
	}
	return (context->best_node);
}

t_node	*find_best_node(t_stack *a, t_stack *b)
{
	t_context	context;
	t_node		*current;

	context.a = a;
	context.b = b;
	context.best_node = NULL;
	context.min_cost = INT_MAX;
	current = b->top;
	while (current)
	{
		context.best_node = compare_best(&context, current);
		current = current->next;
	}
	return (context.best_node);
}
