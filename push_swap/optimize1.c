#include "push_swap.h"

int 	is_biggest(t_node *l, T val)
{
	t_node	*tmp;
	T 		biggest;

	tmp = l;
	biggest = tmp->value;
	while (tmp)
	{
		if(tmp->value > biggest)
			biggest = tmp->value;
		tmp = tmp->next;
	}
	return (biggest == val ? 1 : 0);
}

t_d_linklst	*ft_list_dup_to(t_d_linklst *list)
{
	t_d_linklst	*new;
	t_node		*tmp;
	T			hz;
	int 		i;

	i = 0;
	new = ft_list_dup(list);
	tmp = new->head;
	hz = new->tail->value;
	while (is_biggest(tmp, hz))
	{
		i++;
		new->tail->value = 0;
		new->tail = new->tail->prev;
		hz = new->tail->value;
	}
	//i = (int) ((list->size - i) + 1);
	i = (int) (list->size - i);
	del_list(new);
	tmp = list->head;
	if (tmp != NULL)
		new = creat();
	while (i > 0)
	{
		push_front(new, (int)tmp->value);
		tmp = tmp->next;
		i--;
	}
	/*tmp = list->head;
	if (tmp != NULL)
		new = creat();
	while (i < list->n_size)
	{
		push_front(new, (int)tmp->value);
		tmp = tmp->next;
		i++;
	}*/
	return (new);
}
