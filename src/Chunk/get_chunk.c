#include "../../inc/push_swap.h"

int	get_chunk_size(int stack_size)
{
	if (stack_size <= 25)
		return (5);
	if (stack_size <= 100)
		return (stack_size / 5);
	if (stack_size <= 500)
		return (stack_size / 11);
	return (stack_size / 13);
}
