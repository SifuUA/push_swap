#include "push_swap.h"

void    sort_three_rev(t_d_linklst *list_a)
{
	if (list_a->head->value > list_a->head->next->value &&
		list_a->head->value < list_a->tail->value)
		rrb(list_a);
	else if (list_a->head->value > list_a->head->next->value &&
			 list_a->tail->value > list_a->tail->prev->value)
	{
		sb(list_a);
		rb(list_a);
	}
	else if (list_a->tail->value < list_a->tail->prev->value &&
			 list_a->tail->value < list_a->head->value)
		sb(list_a);
	else if (list_a->head->value < list_a->tail->value &&
			 list_a->tail->value < list_a->tail->prev->value)
	{
		rb(list_a);
	}
	else
	{
		rrb(list_a);
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

	tmp = ft_list_dup(list, len);
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

void	move_from_b(t_d_linklst *list_a, t_d_linklst *list_b, size_t len)
{
	size_t	i;
	size_t 	j;
	size_t 	k;

	i = len / 2;
	j = 0;
	k = 0;
	while (list_a->ar[j] != 0)
		j++;
	list_b->ar[j] = i;
	while (i > 0  && find_min(list_b))
	{
		if (list_b->head->value >= list_b->median)
		{
			pa(list_a, list_b);
			if (list_a->head->value > list_a->head->next->value)
				sa(list_a);
			i--;
		}
		else
		{
			rb(list_b);
			k++;
		}
	}
	while (k > 0)
	{
		rrb(list_b);
		k--;
	}
}

