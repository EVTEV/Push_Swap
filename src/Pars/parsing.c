#include "../../inc/push_swap.h"

int	ft_atoi(const char *str)
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
		if (result * sign > INT_MAX || result * sign < INT_MIN)
			error_exit();
		i++;
	}
	return ((int)(result * sign));
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

void	check_dup(t_stack *stack)
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
				error_exit();
			check = check->next;
		}
		current = current->next;
	}
}

void	do_split(char **av, t_stack *a)
{
	char	**num;
	long	value;
	int		i;

	num = ft_split(av[1], ' ');
	if (!num)
		error_exit();
	i = 0;
	while (num[i])
	{
		if (!is_number(num[i]))
			error_exit();
		value = ft_atoi(num[i]);
		fill_stack(a, value);
		free(num[i]);
		i++;
	}
	free(num);
}

void	fill_good(int ac, char **av, t_stack *a)
{
	long	value;
	int		i;

	if (ac < 2)
		error_exit();
	if (ac == 2)
		do_split(av, a);
	else
	{
		i = 1;
		while (i < ac)
		{
			if (!is_number(av[i]))
				error_exit();
			value = ft_atoi(av[i]);
			fill_stack(a, value);
			i++;
		}
	}
	check_dup(a);
}
