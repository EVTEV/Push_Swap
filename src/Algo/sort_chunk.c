#include "../../inc/push_swap.h"

int	get_chunk_size(int size)
{
	if (size <= 4)
		return (1);
	else if (size <= 100)
		return (5);
	else if (size <= 500)
		return (11);
	return (13);
}

void	set_index_chunk(t_stack *a, int start, int end, int *positions)
{
	t_node	*current;
	int		i;

	current = a->top;
	i = 0;
	while (current)
	{
		positions[i] = -1;
		if (current->index >= start && current->index <= end)
			positions[i] = i;
		current = current->next;
		i++;
	}
}

t_node	*find_next_in_chunk(t_stack *stack, int *positions)
{
	t_node	*current;
	t_node	*best_node;
	int		best_pos;
	int		i;

	current = stack->top;
	best_node = NULL;
	best_pos = stack->size;
	i = 0;
	while (current)
	{
		if (positions[i] != -1 && positions[i] < best_pos)
		{
			best_pos = positions[i];
			best_node = current;
		}
		current = current->next;
		i++;
	}
	return (best_node);
}

void	process_chunk(t_stack *a, t_stack *b, int start, int end)
{
	t_node	*target;
	int		*positions;

	positions = malloc(sizeof(int) * a->size);
	if (!positions)
		return ;
	set_index_chunk(a, start, end, positions);
	while (a->size > 0)
	{
		target = find_next_in_chunk(a, positions);
		if (!target)
			break ;
		move_to_top(a, target);
		pb(b, a);
	}
	free(positions);
}
