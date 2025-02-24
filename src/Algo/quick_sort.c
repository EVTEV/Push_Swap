#include "../../inc/push_swap.h"

static int	partition(int *arr, int low, int high)
{
	int pivot;
	int temp;
	int i;
	int j;

    pivot = arr[high];
    i = low - 1;
    j = low;
    while (j < high)
    {
        if (arr[j] <= pivot)
        {
            i++;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
        j++;
    }
    temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}

void	quick_sort(int *arr, int low, int high)
{
	int	partition_index;

	if (low < high)
    {
        partition_index = partition(arr, low, high);
		quick_sort(arr, low, partition_index - 1);
		quick_sort(arr, partition_index + 1, high);
	}
}
