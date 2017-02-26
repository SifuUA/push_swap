#include "push_swap.h"

size_t		get_position(t_d_linklst *list)
{
	t_node  *tmp;
	T       min;
	size_t	i;
	size_t	pos;

	i = 0;
	tmp = list->head;
	min = list->head->value;
	list->elem_pos = 0;
	pos  = 1;
	while (tmp)
	{
		i++;
		if (tmp->value < min)
		{
			min = tmp->value;
			pos = i;
		}
		tmp = tmp->next;
	}
	list->elem_pos = pos;
	return (pos);
}
size_t		get_pos(t_d_linklst *list)
{
	size_t	pos;

	pos = get_position(list);
	if (pos > list->size / 2)
		return ((list->size - pos) + 1);
	else
		return (pos);
}