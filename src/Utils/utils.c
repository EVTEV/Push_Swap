#include "../../inc/push_swap.h"

int	is_sorted(t_stack *stack)
{
	t_node	*current;

	if (!stack || !stack->top || stack->size <= 1)
		return (1);
	current = stack->top;
	while (current && current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

void	index_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*temp;
	int		index;

	current = stack->top;
	while (current)
	{
		index = 0;
		temp = stack->top;
		while (temp)
		{
			if (current->value > temp->value)
				index++;
			temp = temp->next;
		}
		current->index = index;
		current = current->next;
	}
}

void	normalize_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*compare;
	int		i;

	current = stack->top;
	while (current)
	{
		i = 0;
		compare = stack->top;
		while (compare)
		{
			if (current->value > compare->value)
				i++;
			compare = compare->next;
		}
		current->index = i;
		current = current->next;
	}
}

void	error_exit(void)
{
	write(2, "Error\n", 6);
	exit(1);
}
