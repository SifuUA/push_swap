#include "push_swap.h"

t_d_linklst	*ft_list_dup(t_d_linklst *list)
{
	t_d_linklst	*new;
	t_node		*tmp;

	tmp = list->head;
	new = NULL;
	if (tmp != NULL)
		new = creat();
	while (tmp)
	{
		push_front(new, (int)tmp->value);
		tmp = tmp->next;
	}
	return (new);
}

size_t 	count_small(t_d_linklst *list, T median)
{
	t_node	*tmp;
	size_t 	count;

	count = 0;
	tmp = list->head;
	while (tmp)
	{
		if (tmp->value < median)
			count++;
		tmp = tmp->next;
	}
	return (count);
}

T 	find_median(t_d_linklst *list)
{
	t_d_linklst *tmp;
	t_node		*p;
	size_t 		i;

	tmp = ft_list_dup(list);
	quick_sort(tmp->head, tmp->tail);
	p = tmp->head;
	i = tmp->size / 2;
	while (i > 0)
	{
		p = p->next;
		i--;
	}
	return (p->value);
}
