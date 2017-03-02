#include "push_swap.h"

void 	rra(t_d_linklst *list)
{
	t_node	*tmp;

	if (list->size > 1)
	{
		tmp = list->tail;
		list->tail = list->tail->prev;
		if (list->size > 1)
			list->tail->next = NULL;
		tmp->next = list->head;
		tmp->prev = NULL;
		list->head->prev = tmp;
		list->head = tmp;
		list->count_of_op++;
		put("rra");
	}
}

void 	rrb(t_d_linklst *list)
{
	t_node	*tmp;

	if (list->size > 1)
	{
		tmp = list->tail;
		list->tail = list->tail->prev;
		if (list->size > 1)
			list->tail->next = NULL;
		tmp->next = list->head;
		tmp->prev = NULL;
		list->head->prev = tmp;
		list->head = tmp;
		list->count_of_op++;
		put("rrb");
	}
}

void 	rrr(t_d_linklst *list_a, t_d_linklst *list_b)
{
	rra(list_a);
	rrb(list_b);
	list_a->count_of_op++;
	put("rrr");
}
