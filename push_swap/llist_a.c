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
	i = tmp->size % 2 == 0 ? tmp->size / 2 : tmp->size / 2 + 1;
	while (i > 0)
	{
		p = p->next;
		i--;
	}
	return (p->value);
}
void    sort_three(t_d_linklst *list_a, char **str)
{
	if (list_a->head->value > list_a->head->next->value &&
		list_a->head->value < list_a->tail->value)
		sa(list_a, str);
	else if (list_a->head->value > list_a->head->next->value &&
			 list_a->tail->value > list_a->tail->prev->value)
		ra(list_a, str);
	else if (list_a->tail->value < list_a->tail->prev->value &&
			 list_a->tail->value < list_a->head->value)
		rra(list_a, str);
	else if (list_a->head->value > list_a->tail->value &&
			 list_a->tail->value < list_a->tail->prev->value)
	{
		sa(list_a, str);
		rra(list_a, str);
	}
	else if (list_a->head->value < list_a->tail->value &&
			 list_a->tail->value < list_a->tail->prev->value)
	{
		rra(list_a, str);
		sa(list_a, str);
	}
}

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
