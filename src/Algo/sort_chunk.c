#include "../../inc/push_swap.h"

int	get_chunk_size(int size)
{
	if (size <= 4)
		return (1);
	else if (size <= 100)
		return (5);
	else if (size <= 500)
		return (11);
	return (13);
}
