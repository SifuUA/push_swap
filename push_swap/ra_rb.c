/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_rb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okres <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 13:53:35 by okres             #+#    #+#             */
/*   Updated: 2017/03/15 13:55:37 by okres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_d_linklst *list, char **str)
{
	t_node	*tmp;
	char	*p;

	if (list->size > 1)
	{
		tmp = list->head;
		list->head = tmp->next;
		tmp->prev = list->tail;
		tmp->next = NULL;
		list->tail->next = tmp;
		list->tail = tmp;
		p = *str;
		*str = ft_strjoin(p, "6");
		ft_strdel(&p);
	}
}

void	rb(t_d_linklst *list, char **str)
{
	t_node	*tmp;
	char	*p;

	if (list->size > 1)
	{
		tmp = list->head;
		list->head = tmp->next;
		tmp->prev = list->tail;
		tmp->next = NULL;
		list->tail->next = tmp;
		list->tail = tmp;
		p = *str;
		*str = ft_strjoin(p, "7");
		ft_strdel(&p);
	}
}

void	rr(t_d_linklst *list_a, t_d_linklst *list_b, char **str)
{
	char	*p;

	p = "";
	ra(list_a, &p);
	rb(list_b, &p);
	p = *str;
	*str = ft_strjoin(p, "rr");
	ft_strdel(&p);
}
