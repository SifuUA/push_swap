#include "push_swap.h"

void    move_to_a(t_d_linklst *list_a, t_d_linklst *list_b)
{
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


