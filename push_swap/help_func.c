#include "push_swap.h"

int		is_sort_b(t_d_linklst *b)
{
		t_node  *tmp;
		size_t  i;

		i = 0;
		tmp = b->head;
		while (tmp && tmp->next!= NULL && b->size > 2)
		{
			if (tmp->value > tmp->next->value)
				i++;
			tmp = tmp->next;
		}
		if (i == b->size - 1)
			return (1);
		return (0);
}


