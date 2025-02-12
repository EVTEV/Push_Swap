/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaes <acaes@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 09:17:21 by acaes             #+#    #+#             */
/*   Updated: 2025/02/12 09:17:21 by acaes            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

long	ft_atol(const char *str)
{
	size_t	i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

int	is_number(char *str)
{
	int	i;

	if (!str || !str[0])
		return (0);
	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	check_dup(t_stack *stack)
{
	t_node	*current;
	t_node	*check;

	current = stack->top;
	while (current)
	{
		check = current->next;
		while (check)
		{
			if (current->value == check->value)
				return (0);
			check = check->next;
		}
		current = current->next;
	}
	return (1);
}

void	do_split(char **av, t_stack *a, t_stack *b)
{
	char	**num;
	long	value;
	int		i;

	num = ft_split(av[1], ' ');
	if (!num)
		msg_error(a, b);
	i = 0;
	while (num[i])
	{
		if (!is_number(num[i]))
			msg_error(a, b);
		value = ft_atol(num[i]);
		if (value > INT_MAX || value < INT_MIN)
			msg_error(a, b);
		fill_stack(a, value);
		free(num[i]);
		i++;
	}
	free(num);
}

void	fill_good(int ac, char **av, t_stack *a, t_stack *b)
{
	long	value;
	int		i;

	if (ac < 2)
		msg_error(a, b);
	if (ac == 2)
		do_split(av, a, b);
	else
	{
		i = 1;
		while (i < ac)
		{
			if (!is_number(av[i]))
				msg_error(a, b);
			value = ft_atol(av[i]);
			if (value > INT_MAX || value < INT_MIN)
				msg_error(a, b);
			fill_stack(a, value);
			i++;
		}
		if (!check_dup(a))
			msg_error(a, b);
	}
}
