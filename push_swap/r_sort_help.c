#include "push_swap.h"

void    sort_three_rev(t_d_linklst *list_a, char **str)
{
	if (list_a->head->value > list_a->head->next->value &&
		list_a->head->value < list_a->tail->value)
	{
		rrb(list_a, str);
	}
	else if (list_a->head->value > list_a->head->next->value &&
			 list_a->tail->value > list_a->tail->prev->value)
	{
		sb(list_a, str);
		rb(list_a, str);
	}
	else if (list_a->tail->value < list_a->tail->prev->value &&
			 list_a->tail->value < list_a->head->value)
		sb(list_a, str);
	else if (list_a->head->value < list_a->tail->value &&
			 list_a->tail->value < list_a->tail->prev->value)
	{
		rb(list_a, str);
	}
	else
	{
		rrb(list_a, str);
	}
}

int 	find_min(t_d_linklst *list)
{
	t_node	*tmp;

	tmp = list->head;
	while (tmp)
	{
		if (tmp->value > list->median)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void 	find_median_b(t_d_linklst *list, size_t len)
{
	t_d_linklst *tmp;
	t_node		*p;
	size_t 		i;

	//tmp = ft_list_dup(list, len);
	quick_sort(tmp->head, tmp->tail);
	p = tmp->head;
	i = tmp->size / 2;
	while (i > 0)
	{
		p = p->next;
		i--;
	}
	list->median = p->value;
}

size_t 	count_large(t_d_linklst *list, T median)
{
	t_node	*tmp;
	size_t 	count;

	count = 0;
	tmp = list->head;
	while (tmp)
	{
		if (tmp->value >= median)
			count++;
		tmp = tmp->next;
	}
	return (count);
}
