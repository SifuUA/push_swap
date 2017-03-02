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

void	move_from(t_d_linklst *list_a, t_d_linklst *list_b)
{
	size_t	i;

	i = list_a->size / 2;
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

void	r_sort(t_d_linklst *list_a, t_d_linklst *list_b)
{
	if (list_a->size > 1)
	{
		find_median(list_a);
		move_from(list_a, list_b);
		r_sort(list_a, list_b);
	}
	else if (list_b)
}
