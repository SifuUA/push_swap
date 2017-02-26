#include "push_swap.h"

void    sort_three(t_d_linklst *list_a)
{
	if (list_a->head->value > list_a->head->next->value &&
			list_a->head->value < list_a->tail->value)
		sa(list_a);
	else if (list_a->head->value > list_a->head->next->value &&
			list_a->tail->value > list_a->tail->prev->value)
		ra(list_a);
	else if (list_a->tail->value < list_a->tail->prev->value &&
			list_a->tail->value < list_a->head->value)
		rra(list_a);
	else if (list_a->head->value > list_a->tail->value &&
			list_a->tail->value < list_a->tail->prev->value)
	{
		sa(list_a);
		rra(list_a);
	}
	else if (list_a->head->value < list_a->tail->value &&
			list_a->tail->value < list_a->tail->prev->value)
	{
		rra(list_a);
		sa(list_a);
	}
}

void    sort_four_five(t_d_linklst *list_a, t_d_linklst *list_b)
{
	size_t	i;
	size_t	j;
	size_t	new_pos;

	i = 0;
	while (i < 2)
	{
		j = 0;
		new_pos = get_pos(list_a);
		while (j < new_pos)
		{
			if (list_a->elem_pos > list_a->size / 2)
				rra(list_a);
			else if (new_pos != 1)
			{
				ra(list_a);
				j++;
			}
			j++;
		}
		pb(list_a, list_b);
		i++;
	}
	little_sort(list_a, list_b);
}

void    little_sort(t_d_linklst *list_a, t_d_linklst *list_b)
{
	if (is_sort(list_a))
	{
		replace_to_a(list_a, list_b);
		return;
	}
	if (list_a->size == 2)
	{
		if (list_a->head->value > list_a->tail->value)
			sa(list_a);
		replace_to_a(list_a, list_b);
	}
	else if (list_a->size == 3)
		sort_three(list_a);
	else if (list_a->size >= 4 && list_a->size <= 5)
		sort_four_five(list_a, list_b);

}
