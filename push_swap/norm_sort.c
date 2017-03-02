#include "push_swap.h"
void    check(t_d_linklst *list);
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
		//while (i < new_pos)
		while (list_a->head->value != list_a->min)
		{
			//if (list_a->head->value > list_a->head->next->value)
			//{
			//	sa(list_a);
			//	continue;
		//	}
			size_t size = list_a->size / 2;
			size = list_a->size % 2 > 0 ? size + 1 : size;
			if (list_a->elem_pos <= size)
			{
				ra(list_a);
				//check(list_a);
			}
			else
			{
				rra(list_a);
				i++;
			}
			i++;
		}
		pb(list_a, list_b);
		//if (list_a->head->value > list_a->head->next->value)
			//sa(list_a);
	}
	little_sort(list_a, list_b);
}

void    check(t_d_linklst *list)
{
	if (list->head > list->head->next)
		sa(list);
	else if (list->tail < list->tail->prev && list->tail > list->head)
	{
		rra(list);
		rra(list);
		sa(list);
		ra(list);
		ra(list);
	}
	else if (list->head > list->head->next && list->tail < list->head)
		ra(list);
	else if (list->tail < list->head && list->tail < list->tail->prev)
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

