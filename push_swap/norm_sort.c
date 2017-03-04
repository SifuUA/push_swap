#include "push_swap.h"

void    replace_to_a(t_d_linklst *list_a, t_d_linklst *list_b)
{
	while (list_b->size > 0)
		pa(list_a, list_b);
}

void    replace_to_b(t_d_linklst *list_a, t_d_linklst *list_b)
{
	size_t  i;
	size_t 	new_pos;

	while (list_a->size > 5)
	{
		i = 0;
		new_pos = get_pos(list_a);
		while (i < new_pos)
		{
			if (list_a->elem_pos > list_a->size / 2)
				rra(list_a);
			else if (new_pos != 1)
			{
				ra(list_a);
				i++;
			}
			i++;
		}
		pb(list_a, list_b);
	}
	little_sort(list_a, list_b);
}

void    check(t_d_linklst *list)
{
	if (list->head->value > list->head->next->value)
		sa(list);
	else if (list->tail->value < list->tail->prev->value && list->tail->value > list->head->value)
	{
		rra(list);
		rra(list);
		sa(list);
		ra(list);
		ra(list);
	}
	else if (list->head->value > list->head->next->value && list->tail->value < list->head->value)
		ra(list);
	else if (list->tail->value < list->head->value && list->tail->value < list->tail->prev->value)
		rra(list);
}

void    norm_sort(t_d_linklst *list_a, t_d_linklst *list_b)
{
	check(list_a);
	if (is_sort(list_a))
		return ;
	replace_to_b(list_a, list_b);
	replace_to_a(list_a, list_b);

}

