#include "push_swap.h"

void 	ra(t_d_linklst *list)
{
	t_node	*tmp;

	if (list->size > 1)
	{
		tmp = list->head;
		list->head = tmp->next;
		tmp->prev = list->tail;
		tmp->next = NULL;
		list->tail->next = tmp;
		list->tail = tmp;
		list->count_of_op++;
		put("ra");
	}
}

void 	rb(t_d_linklst *list)
{
	t_node	*tmp;

	if (list->size > 1)
	{
		tmp = list->head;
		list->head = tmp->next;
		tmp->prev = list->tail;
		tmp->next = NULL;
		list->tail->next = tmp;
		list->tail = tmp;
		list->count_of_op++;
		put("rb");
	}
}

void 	rr(t_d_linklst *list_a, t_d_linklst *list_b)
{
	ra(list_a);
	rb(list_b);
	put("rr");
	list_a->count_of_op++;

}