#include "push_swap.h"

void	little_help(t_d_linklst *list_a, t_d_linklst *list_b)
{
	//if (list_b->head != NULL && list_b->size > 1 && list_b->head->value < list_b->head->next->value)
	//	sb(list_b);
	if (list_a->head != NULL && list_a->size > 1 && list_a->head->value > list_a->head->next->value)
		sa(list_a);
}

void    move_to_a(t_d_linklst *list_a, t_d_linklst *list_b)
{
	little_help(list_a, list_b);
	while (list_b->size > 0)
		pa(list_a, list_b);
}

int 	most_close_min(t_d_linklst *list, T med)
{
	t_node	*tmp;
	int 	i;

	tmp = list->head;
	i = 1;
	while (tmp)
	{
		if (tmp->value < med)
			return (i);
		i++;
		tmp = tmp->next;
	}
	return (0);
}

int 	most_close_max(t_d_linklst *list, T med)
{
	t_node	*tmp;
	int 	i;

	tmp = list->head;
	i = 1;
	while (tmp)
	{
		if (tmp->value > med)
			return (i);
		i++;
		tmp = tmp->next;
	}
	return (0);
}

void    optimize_check(t_d_linklst *list)
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

