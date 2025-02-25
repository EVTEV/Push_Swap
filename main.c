/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaes <acaes@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 09:14:03 by acaes             #+#    #+#             */
/*   Updated: 2025/02/12 09:14:03 by acaes            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"
/*
static void	print_stack(t_stack *stack, char *msg)
{
	t_node	*current;

	if (!stack)
		return ;
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

	a = NULL;
	b = NULL;
	a = init_stack();
	if (!a)
		return (0);
	b = init_stack();
	if (!b)
	{
		free_stack(a);
		return (0);
	}
	fill_good(ac, av, a, b);
	push_swap(a, b);
	free_stack(a);
	free_stack(b);
	return (0);
}
