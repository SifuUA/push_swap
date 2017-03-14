/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bum_bum.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okres <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 21:26:44 by okres             #+#    #+#             */
/*   Updated: 2017/03/14 21:38:03 by okres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	f_1(int i, t_d_linklst *a, t_d_linklst *b, char **str)
{
	ra(a, str);
	while (i > 0)
	{
		pa(a, b, str);
		i--;
	}
}

void	f_2(T num, t_d_linklst *a, t_d_linklst *b, char **str)
{
	a->size--;
	a->n_size--;
	bum(a, b, str);
	rra(a, str);
	a->size++;
	a->n_size++;
	if (a->tail->value == num)
		rra(a, str);
}

void	f_3(t_d_linklst *a, t_d_linklst *b, t_d_linklst *c, char **str)
{
	pb(a, b, str);
	c->i++;
}

void	sort_four(t_d_linklst *a, t_d_linklst *b, t_d_linklst *c, char **str)
{
	quick_sort(c->head, c->tail);
	c->f = a->size != (a->f_size + a->n_size) ? 1 : 0;
	c->i = 0;
	if (!is_sort(a))
	{
		while (a->head->value != c->head->value)
		{
			if (c->f == 0)
			{
				if (min_s(a, str))
				{
					c->f = 2;
					break ;
				}
				a->tail->value == c->head->value ? rra(a, str) : ra(a, str);
			}
			else
				f_3(a, b, c, str);
		}
		c->f != 2 ? f_1(c->i, a, b, str) : c->f;
		f_2(c->head->value, a, b, str);
	}
	del_list(c);
}

void	bum(t_d_linklst *a, t_d_linklst *b, char **str)
{
	t_d_linklst *c;

	a->i = 0;
	a->j = 0;
	c = ft_list_dup(a);
	if ((a->size == 4 || a->n_size == 4) && b->size <= 3 && !is_sort(a))
	{
		sort_four(a, b, c, str);
		return ;
	}
	else if (a->size + b->size == a->f_size && b->size == 3)
		sort_three_dow_b(b, str);
	if (a->n_size <= 3 && b->size <= 3 && a->size != a->f_size)
		f_4(a, b, str);
	if (c)
		del_list(c);
}
