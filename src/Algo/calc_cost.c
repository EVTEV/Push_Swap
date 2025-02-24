#include "../../inc/push_swap.h"

static int	abs_val(int n)
{
    if (n < 0)
        return (-n);
    return (n);
}

static int	get_cost_a(t_stack *a, t_node *target)
{
    int pos; 

	pos	= get_node_position(a, target);
    if (pos > a->size / 2)
        return (-(a->size - pos));
    return (pos);
}

static int	get_cost_b(t_stack *b, t_node *node)
{
    int pos;
    
	pos = get_node_position(b, node);
    if (pos > b->size / 2)
        return (-(b->size - pos));
    return (pos);
}

static t_cost calculate_cost(t_stack *a, t_stack *b, t_node *node)
{
    t_cost cost;
    t_node *target;
    int max_abs;

    target = find_target_position(a, node->value);
    cost.cost_b = get_cost_b(b, node);
    cost.cost_a = get_cost_a(a, target);

    if ((cost.cost_a > 0 && cost.cost_b > 0) || 
        (cost.cost_a < 0 && cost.cost_b < 0))
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

t_node	*find_best_node(t_stack *a, t_stack *b) 
{
	t_node *current = b->top;
	t_node *best_node = NULL;
	int min_cost = INT_MAX;
	while (current)
	{
		t_cost cost = calculate_cost(a, b, current);
		if (cost.total < min_cost)
		{
			min_cost = cost.total;
			best_node = current;
		}
		else if (cost.total == min_cost)
		{
			t_cost best_cost = calculate_cost(a, b, best_node);
			if (abs_val(cost.cost_a) + abs_val(cost.cost_b) < 
				abs_val(best_cost.cost_a) + abs_val(best_cost.cost_b))
				best_node = current;
		}
		current = current->next;
	}
	return (best_node);
}
