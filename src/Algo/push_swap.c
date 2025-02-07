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
/*
void	sort_stack(t_stack *a, t_stack *b)
{
	t_node	*max;
	t_node	*min;

	while (a->size > 3)
		pb(b, a);
	sort_three(a);
	while (b->size)
	{
		max = get_max_node(b);
		move_to_top(b, max);
		pa(a, b);
	}
	min = get_min_node(a);
	move_to_top(a, min);
}
*/

void	sort_stack(t_stack *a, t_stack *b)
{
	int	size;
    int	max_bits;
    int	i;
    int	j;

	normalize_stack(a);
	size = a->size;
	max_bits = 0;
	while ((size - 1) >> max_bits)
		max_bits++;
	i = 0;
    while (i < max_bits)
    {
		j = 0;
        while (j < size)
        {
            if (((a->top->index >> i) & 1) == 1)
                ra(a);
            else
                pb(b, a);
			j++;
        }
        while (b->top)
            pa(a, b);
		i++;
    }
}

void	push_swap(t_stack *a, t_stack *b)
{
	if (!a || !a->top || a->size <= 1)
		return ;
	if (a->size == 2)
	{
		ft_printf("stack = 2\n");
		sa(a);
	}
	else if (a->size == 3)
	{
		ft_printf("stack = 3\n");
		sort_three(a);
	}
	else
	{
		ft_printf("big stack\n");
		sort_stack(a, b);
	}
}
