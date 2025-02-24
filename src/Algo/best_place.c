/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_place.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaes <acaes@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 23:47:55 by acaes             #+#    #+#             */
/*   Updated: 2025/02/24 23:47:55 by acaes            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static int	*sorted_array(t_stack *a)
{
	t_node	*temp;
	int		*sorted;
	int		i;

	if (!a->top)
		return (NULL);
	sorted = malloc(sizeof(int) * a->size);
	if (!sorted)
		return (NULL);
	i = 0;
	temp = a->top;
	while (temp)
	{
		sorted[i++] = temp->value;
		temp = temp->next;
	}
	quick_sort(sorted, 0, a->size - 1);
	return (sorted);
}

static t_node	*compare(t_stack *a, int sorted, int value, int *min_diff)
{
	t_node	*found;
	t_node	*best_target;

	best_target = NULL;
	if (sorted > value && sorted - value < *min_diff)
	{
		*min_diff = sorted - value;
		found = find_node_by_value(a, sorted);
		if (found)
			best_target = found;
	}
	return (best_target);
}

static t_node	*find_best_target(t_stack *a, int *sorted, int value)
{
	t_node	*best_target;
	t_node	*current_target;
	int		min_diff;
	int		left;
	int		right;
	int		mid;

	best_target = NULL;
	min_diff = INT_MAX;
	left = 0;
	right = a->size - 1;
	while (left <= right)
	{
		mid = left + (right - left) / 2;
		current_target = compare(a, sorted[mid], value, &min_diff);
		if (current_target)
			best_target = current_target;
		if (sorted[mid] < value)
			left = mid + 1;
		else
			right = mid - 1;
	}
	return (best_target);
}

t_node	*find_target_position(t_stack *a, int value)
{
	t_node	*best_target;
	int		*sorted;

	sorted = sorted_array(a);
	if (!sorted)
		return (NULL);
	best_target = find_best_target(a, sorted, value);
	free(sorted);
	if (best_target)
		return (best_target);
	return (get_min_node(a));
}
