#include "push_swap.h"

int     is_sort(t_d_linklst *list)
{
	t_node  *tmp;
	size_t  i;

	i = 0;
	tmp = list->head;
	while (tmp->next != NULL)
	{
		if (tmp->value < tmp->next->value)
			i++;
		tmp = tmp->next;
	}
	if (i == list->size - 1)
		return (1);
	return (0);
}

void    push_swap(t_d_linklst *list_a, t_d_linklst *list_b)
{
	if (is_sort(list_a) && list_b->size == 0)
		printList(list_a);
	else
	{
		if (list_a->size <= 5)
			little_sort(list_a, list_b);
		else
			norm_sort(list_a, list_b);
	}
}

