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

void	move_to_top(t_stack *stack, t_node *target)
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
	if (pos <= stack->size / 2)
	{
		while (stack->top != target)
			rotate(stack);
	}
	else
	{
		while (stack->top != target)
			reverse(stack);
	}
}
