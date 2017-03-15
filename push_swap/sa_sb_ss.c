/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_sb_ss.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okres <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 13:57:31 by okres             #+#    #+#             */
/*   Updated: 2017/03/15 14:00:46 by okres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_d_linklst *list_a, char **str)
{
	long int	tmp;
	char		*p;

	if (list_a->size > 1)
	{
		tmp = list_a->head->value;
		list_a->head->value = list_a->head->next->value;
		list_a->head->next->value = tmp;
		p = *str;
		*str = ft_strjoin(p, "3");
		ft_strdel(&p);
	}
}

void	sb(t_d_linklst *list_b, char **str)
{
	long int	tmp;
	char		*p;

	if (list_b->size > 1)
	{
		tmp = list_b->head->value;
		list_b->head->value = list_b->head->next->value;
		list_b->head->next->value = tmp;
		p = *str;
		*str = ft_strjoin(p, "4");
		ft_strdel(&p);
	}
}

void	ss(t_d_linklst *list_a, t_d_linklst *list_b, char **str)
{
	char	*p;

	p = "";
	sa(list_a, &p);
	sb(list_b, &p);
	p = *str;
	*str = ft_strjoin(p, "ss");
	ft_strdel(&p);
}
