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

t_node	*find_target_node(t_stack *stack, int start, int end)
{
	t_node	*current;
	t_node	*best;
	int		best_pos;
	int		curr_pos;

	best = NULL;
	best_pos = stack->size;
	current = stack->top;
	curr_pos = 0;
	while (current)
	{
		if (current->index >= start && current->index <= end)
		{
			if (!best || curr_pos < best_pos)
			{
				best = current;
				best_pos = curr_pos;
			}
		}
		current = current->next;
		curr_pos++;
	}
	return (best);
}

int	get_size_node(int size)
{
	if (size <= 100)
		return (size / 5);
	return (size / 11);
}

int	get_pos_node(t_stack *stack, t_node *target)
{
	t_node	*current;
	int		pos;

	pos = 0;
	current = stack->top;
	while (current != target)
	{
		pos++;
		current = current->next;
	}
	return (pos);
}
