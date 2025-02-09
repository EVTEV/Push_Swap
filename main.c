#include "inc/push_swap.h"

/*
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
*/

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = init_stack();
	b = init_stack();
	fill_good(ac, av, a);
	push_swap(a, b);
	free_stack(a);
	free_stack(b);
	return (0);
}
