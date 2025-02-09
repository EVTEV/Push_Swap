#include "../../inc/push_swap.h"

void	sort_three(t_stack *a)
{
	t_node	*max;

	max = get_max_node(a);
	if (a->top == max)
		ra(a);
	else if (a->top->next == max)
		rra(a);
	if (a->top->value > a->top->next->value)
		sa(a);
}

void	sort_stack(t_stack *a, t_stack *b)
{
	t_node	*max;
	int		size;
	int		start;

	normalize_stack(a);
	size = get_size_node(a->size);
	start = 0;
	while (start < a->size)
	{
		push_node(a, b, start, (start + size - 1));
		start += size;
	}
	while (b->size > 0)
	{
		max = get_max_node(b);
		rotate_to_top(b, max, 'b');
		pa(a, b);
	}
}

void	push_swap(t_stack *a, t_stack *b)
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
