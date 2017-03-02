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

void 	find_median(t_d_linklst *list)
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
	list->median = p->value;
}

void 	find_median_b(t_d_linklst *list, size_t len)
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
	list->median = p->value;
}

void	move_from(t_d_linklst *list_a, t_d_linklst *list_b, size_t len)
{
	size_t	i;
	size_t 	j;

	i = list_a->size / 2;
	j = 0;
	while (list_b->ar[j] != 0)
		j++;
	list_b->ar[j] = i;
	len = i;
	while (i > 0)
	{
		if (list_a->head->value < list_a->median)
		{
			pb(list_a, list_b);
			i--;
		}
		else
			ra(list_a);
	}
}

void	r_sort(t_d_linklst *list_a, t_d_linklst *list_b, size_t len)
{
	if (list_a->size > 3)
	{
		find_median(list_a);
		move_from(list_a, list_b, len);
		r_sort(list_a, list_b, len);
	}
	else if (list_b->size > 3)
	{
		find_median(list_b);
		move_from(list_a, list_b, len);
		r_sort(list_a, list_b, len);
	}
}
