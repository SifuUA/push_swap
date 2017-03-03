#include "push_swap.h"

size_t 	count_large(t_d_linklst *list, T median)
{
	t_node	*tmp;
	size_t 	count;

	count = 0;
	tmp = list->head;
	while (tmp)
	{
		if (tmp->value > median)
			count++;
		tmp = tmp->next;
	}
	return (count);
}
