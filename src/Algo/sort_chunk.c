#include "../../inc/push_swap.h"

int	*stack_to_array(t_stack *stack, int size) 
{
	t_node	*current;
    int 	*arr;
	int		i;

	arr = (int *)malloc(sizeof(int) * size);
    if (!arr)
        return NULL;
	current = stack->top;
	i = 0;
    while (i < size) 
	{
        arr[i] = current->value;
        current = current->next;
		i++;
    }
    return (arr);
}

void	sort_array(int *arr, int size) 
{
    int	temp;
	int	i;
	int	j;

	i = 0;
    while (i < size - 1) 
	{
		j = 0;
        while (j < size - i - 1) 
		{
            if (arr[j] > arr[j + 1]) 
			{
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
			j++;
        }
		i++;
    }
}

int	find_pivot(t_stack *stack) 
{
	int	*arr;
	int	pivot;

	if (!stack || stack->size == 0)
        return 0;
	arr = stack_to_array(stack, stack->size);
    if (!arr)
        return 0;
    sort_array(arr, stack->size);
    pivot = arr[stack->size / 2];
	free(arr);
    return (pivot);
}
