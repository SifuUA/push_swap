#include "push_swap.h"

void 	rra(t_d_linklst *list, char **str)
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
		p = *str;
		*str = ft_strjoin(p, "9");
		ft_strdel(&p);
	}
}

void 	rrb(t_d_linklst *list, char **str)
{
	t_node	*tmp;
	char	*p;

	if (list->size > 0)
	{
		tmp = list->tail;
		list->tail = list->tail->prev;
		if (list->size > 1)
			list->tail->next = NULL;
		tmp->next = list->head;
		tmp->prev = NULL;
		list->head->prev = tmp;
		list->head = tmp;
		p = *str;
		*str = ft_strjoin(p, "0");
		ft_strdel(&p);
	}
}

void 	rrr(t_d_linklst *list_a, t_d_linklst *list_b, char **str)
{
	char	*p;

	p = "";
	rra(list_a, &p);
	rrb(list_b, &p);
	p = *str;
	*str = ft_strjoin(p, "rrr");
	ft_strdel(&p);
}
