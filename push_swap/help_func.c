/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okres <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 13:05:59 by okres             #+#    #+#             */
/*   Updated: 2017/03/15 13:07:08 by okres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		is_sort_b(t_d_linklst *b)
{
	t_node	*tmp;
	size_t	i;

	i = 0;
	tmp = b->head;
	if (b->size == 2)
	{
		if (b->head->value > b->tail->value)
			return (1);
		else
			return (0);
	}
	while (tmp && tmp->next != NULL && b->size > 2)
	{
		if (tmp->value > tmp->next->value)
			i++;
		tmp = tmp->next;
	}
	if (i == b->size - 1)
		return (1);
	return (0);
}

void	rra_mod(t_d_linklst *list)
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
	}
}

void	sa_mod(t_d_linklst *list_a)
{
	long int tmp;

	if (list_a->size > 1)
	{
		tmp = list_a->head->value;
		list_a->head->value = list_a->head->next->value;
		list_a->head->next->value = tmp;
	}
}

void	move_to_a(t_d_linklst *list_a, t_d_linklst *list_b, char **str)
{
	while (list_b->size > 0)
		pa(list_a, list_b, str);
}
