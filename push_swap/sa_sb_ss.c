#include "push_swap.h"

void    sa(t_d_linklst *list_a)
{
	T tmp;

	if (list_a->size > 1)
	{
		tmp = list_a->head->value;
		list_a->head->value = list_a->head->next->value;
		list_a->head->next->value = tmp;
		list_a->count_of_op++;
		put("sa");
	}
}

void    sb(t_d_linklst *list_b)
{
	T tmp;

	if (list_b->size > 1)
	{
		tmp = list_b->head->value;
		list_b->head->value = list_b->head->next->value;
		list_b->head->next->value = tmp;
		list_b->count_of_op++;
		put("sb");
	}
}

void    ss(t_d_linklst *list_a, t_d_linklst *list_b)
{
	sa(list_a);
	sb(list_b);
	list_a->count_of_op++;
	put("ss");
}
