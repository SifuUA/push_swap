/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   llist_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okres <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 13:10:34 by okres             #+#    #+#             */
/*   Updated: 2017/03/15 13:11:01 by okres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_d_linklst	*ft_list_dup(t_d_linklst *list)
{
	t_d_linklst	*new;
	t_node		*tmp;

	tmp = list->head;
	if (tmp != NULL)
		new = creat();
	else
		return (NULL);
	while (tmp)
	{
		push_front(new, (int)tmp->value);
		tmp = tmp->next;
	}
	new->f_size = list->f_size;
	return (new);
}

size_t		count_small(t_d_linklst *list, long int median)
{
	t_node	*tmp;
	size_t	count;

	count = 0;
	tmp = list->head;
	while (tmp)
	{
		if (tmp->value < median)
			count++;
		tmp = tmp->next;
	}
	return (count);
}

long int	find_median(t_d_linklst *list)
{
	t_d_linklst	*tmp;
	t_node		*p;
	size_t		i;

	tmp = ft_list_dup(list);
	quick_sort(tmp->head, tmp->tail);
	p = tmp->head;
	i = tmp->size / 2;
	while (i > 0)
	{
		p = p->next;
		i--;
	}
	return (p->value);
}

int			is_sort(t_d_linklst *list)
{
	t_node	*tmp;
	size_t	i;

	i = 0;
	tmp = list->head;
	while (tmp->next != NULL)
	{
		if (tmp->value < tmp->next->value)
			i++;
		tmp = tmp->next;
	}
	if (i == list->size - 1)
		return (1);
	return (0);
}
