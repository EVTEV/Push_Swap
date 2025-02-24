#include "../../inc/push_swap.h"

static int	get_optimal_move(t_stack *stack, t_node *target)
{
	t_node *current; 
	int pos;

	current = stack->top;
	pos = 0;
    while (current && current != target)
	{
        pos++;
        current = current->next;
    }
    if (pos > stack->size / 2)
        return (pos - stack->size);
    return (pos);
}

static void	rotate_both(t_stack *a, t_stack *b, int *pos_a, int *pos_b)
{
    if (*pos_a > a->size / 2)
        *pos_a = *pos_a - a->size;
    if (*pos_b > b->size / 2)
        *pos_b = *pos_b - b->size;
    while (*pos_a && *pos_b)
    {
        if ((*pos_a > 0 && *pos_b > 0) || (*pos_a < 0 && *pos_b < 0))
        {
            if (*pos_a > 0)
            {
                rr(a, b);
                (*pos_a)--;
                (*pos_b)--;
            }
            else
            {
                rrr(a, b);
                (*pos_a)++;
                (*pos_b)++;
            }
        }
        else
            break ;
    }
}

static void calculate_move(t_stack *a, t_stack *b, t_node *node, t_pos *pos)
{
    t_node *target;
   
	target = find_target_position(a, node->value);
    pos->pos_b = get_optimal_move(b, node);
    pos->pos_a = get_optimal_move(a, target);
}

static void	rotate_stack(t_stack *a, t_stack *b, int pos_a, int pos_b)
{
    rotate_both(a, b, &pos_a, &pos_b);
    while (pos_a > 0)
    {
        ra(a);
        pos_a--;
    }
    while (pos_a < 0)
    {
        rra(a);
        pos_a++;
    }
    while (pos_b > 0)
    {
        rb(b);
        pos_b--;
    }
    while (pos_b < 0)
    {
        rrb(b);
        pos_b++;
    }
}

void	execute_move(t_stack *a, t_stack *b, t_node *node)
{
    t_pos	pos;

    calculate_move(a, b, node, &pos);
    rotate_stack(a, b, pos.pos_a, pos.pos_b);
    pa(a, b);
}



