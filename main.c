#include "inc/push_swap.h"

static void	ft_print_lst(t_stack *stack, char *msg)
{
	t_node	*current;

	current = stack->top;
	ft_printf("%s\n", msg);
	while (current)
	{
		ft_printf("%d\n", current->value);
		current = current->next;
	}
}

int	main(int ac, char **av)
{
    t_stack	*a;
    t_stack	*b;

    a = init_stack();
    b = init_stack();
    fill_good(ac, av, a);
	ft_print_lst(a, "stack de base");
	if (is_sorted(a))
		ft_printf("Stack already sorted");
	else
	{
		push_swap(a, b);
		if (!is_sorted(a))
			ft_print_lst(a, "push_swap don't work");
		else
			ft_print_lst(a, "Stack is sorted");
	}
    free_stack(a);
    free_stack(b);
    return (0);
}
