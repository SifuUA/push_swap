/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okres <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 13:24:52 by okres             #+#    #+#             */
/*   Updated: 2017/03/15 13:53:00 by okres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t		count_large(t_d_linklst *list, long int median)
{
	t_node	*tmp;
	size_t	count;

	count = 0;
	tmp = list->head;
	while (tmp)
	{
		if (tmp->value >= median)
			count++;
		tmp = tmp->next;
	}
	return (count);
}

void		help_dup(t_d_linklst *list, t_d_linklst *new, t_node *tmp)
{
	while (list->i > 0)
	{
		push_front(new, (int)tmp->value);
		tmp = tmp->next;
		list->i--;
	}
}

int			if_biggest(t_d_linklst *l, long int val)
{
	t_node		*tmp;
	long int	biggest;

	tmp = l->head;
	biggest = tmp->value;
	while (tmp)
	{
		if (tmp->value > biggest)
			biggest = tmp->value;
		tmp = tmp->next;
	}
	return (biggest == val ? 1 : 0);
}

t_d_linklst	*ft_list_dup_to(t_d_linklst *list)
{
	t_d_linklst	*new;
	t_node		*tmp;

	list->i = 0;
	new = ft_list_dup(list);
	new->num = new->tail->value;
	while (if_biggest(new, new->num))
	{
		list->i++;
		new->tail->value = -2147483649;
		new->tail = new->tail->prev;
		new->num = new->tail->value;
	}
	list->i = (int)(list->size - list->i);
	del_list(new);
	tmp = list->head;
	if (tmp != NULL)
		new = creat();
	help_dup(list, new, tmp);
	return (new);
}

void		initial(t_d_linklst *a, t_d_linklst *b)
{
	t_d_linklst *c;

	b->i = 0;
	a->n_size = 0;
	a->flag = 1;
	c = ft_list_dup(b);
	quick_sort(c->head, c->tail);
	b->med = find_median(c);
	b->count = count_large(c, b->med);
	if (c)
		del_list(c);
}
