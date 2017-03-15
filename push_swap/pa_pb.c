/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okres <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 13:26:48 by okres             #+#    #+#             */
/*   Updated: 2017/03/15 13:27:29 by okres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_d_linklst *list_a, t_d_linklst *list_b, char **str)
{
	char	*p;

	if (list_b->size == 0)
		return ;
	push_head(list_a, list_b);
	p = *str;
	*str = ft_strjoin(p, "1");
	ft_strdel(&p);
}

void	pb(t_d_linklst *list_a, t_d_linklst *list_b, char **str)
{
	char	*p;

	if (list_a->size == 0)
		return ;
	push_head(list_b, list_a);
	p = *str;
	*str = ft_strjoin(p, "2");
	ft_strdel(&p);
}
