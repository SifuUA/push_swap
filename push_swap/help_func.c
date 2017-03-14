#include "push_swap.h"

int		is_sort_b(t_d_linklst *b)
{
		t_node  *tmp;
		size_t  i;

		i = 0;
		tmp = b->head;
		if (b->size == 2)
		{
			if (b->head->value > b->tail->value)
				return (1);
			else
				return (0);
		}
		while (tmp && tmp->next!= NULL && b->size > 2)
		{
			if (tmp->value > tmp->next->value)
				i++;
			tmp = tmp->next;
		}
		if (i == b->size - 1)
			return (1);
		return (0);
}

void 	rra_mod(t_d_linklst *list)
{
	t_node	*tmp;
	char 	*p;

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
	}
}

void    sa_mod(t_d_linklst *list_a)
{
	T 		tmp;

	if (list_a->size > 1)
	{
		tmp = list_a->head->value;
		list_a->head->value = list_a->head->next->value;
		list_a->head->next->value = tmp;
	}
}

int 	try_help(t_d_linklst *l, int i)
{
	t_d_linklst *new;

	new = ft_list_dup(l);
	while (i > 0)
	{
		rra_mod(new);
		if (new->head != NULL && new->size > 1 && new->head->value > new->head->next->value)
			sa_mod(new);
		i--;
	}
	return (is_sort(new) ? 1 : 0);
}

