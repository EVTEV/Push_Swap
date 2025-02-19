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

void    sort_four(t_stack *a, t_stack *b)
{
	t_node  *min;

	min = get_min_node(a);
    while (a->top != min)
        ra(a);
    pb(b, a);
    sort_three(a);
    pa(a, b);
}

void    sort_five(t_stack *a, t_stack *b)
{
    t_node *m1;
    t_node *m2;

	m1 = get_min_node(a);
    while (a->top != m1)
        ra(a);
    pb(b, a);
    m2 = get_max_node(a);
    while (a->top != m2) 
        ra(a);
    pb(b, a);
    sort_three(a);
    pa(a, b);
	ra(a);
    pa(a, b);
}

