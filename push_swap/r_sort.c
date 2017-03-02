#include "push_swap.h"

t_d_linklst	*ft_list_dup(t_d_linklst *list, size_t size)
{
	t_d_linklst	*new;
	t_node		*tmp;

	tmp = list->head;
	new = NULL;
	if (tmp != NULL)
		new = creat();
	while (tmp && size > 0)
	{
		push_front(new, (int)tmp->value);
		tmp = tmp->next;
		size--;
	}
	return (new);
}

void 	find_median(t_d_linklst *list)
{
	t_d_linklst *tmp;
	t_node		*p;
	size_t 		i;

	tmp = ft_list_dup(list, list->size);
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


void	move_from_a(t_d_linklst *list_a, t_d_linklst *list_b)
{
	size_t	i;
	size_t 	j;

	i = list_a->size / 2;
	j = 0;
	while (list_b->ar[j] != 0)
		j++;
	list_b->ar[j] = i;
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
	T i;

	i = 0;
	if (list_a->size > 3)
	{
		find_median(list_a);
		move_from_a(list_a, list_b);
		r_sort(list_a, list_b, len);
	}
	if (list_a->size <= 3 && !is_sort(list_a))
		sort_three(list_a);
	while (list_b->ar[i] != 0 && list_b->head != NULL)
		i++;
	i--;
	if (list_b->ar[i] > 3)
	{

		find_median_b(list_b, list_b->ar[i]);
		move_from_b(list_a, list_b, list_b->ar[i]);
		r_sort(list_a, list_b, len);
	}
	int j = (int) list_b->ar[i];
	while (j > 0 && list_b->head != NULL)
	{
		if (list_b->size <= 3 && list_b->head != NULL)
		{
			sort_three_rev(list_b);
			replace_to_a(list_a, list_b);
		}
		else if (list_b->head->value < list_b->head->next->value && j >= 1)
			sb(list_b);
		pa(list_a, list_b);
		j--;
	}
	list_b->ar[i] = 0;
}
