#include "../../inc/push_swap.h"

void	sort_two(t_stack *a)
{
	if (a->top->value > a->top->next->value)
		sa(a);
}

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

void	sort_four(t_stack *a, t_stack *b)
{
	int min_pos; 

	min_pos = find_min_position(a);
    while (min_pos > 0)
    {
        ra(a);
        min_pos--;
    }
    pb(a, b);
    sort_three(a);
    pa(b, a);
}
