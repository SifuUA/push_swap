/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_m_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okres <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 13:49:15 by okres             #+#    #+#             */
/*   Updated: 2017/03/15 13:49:16 by okres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	piv_a1(t_d_linklst *a, t_d_linklst *b, char **str, int i)
{
	if (a->flag != 0)
	{
		while (i > 0)
		{
			rra(a, str);
			i--;
		}
	}
	if (a->size <= 4)
		a->flag = 0;
	a->fack = 0;
	r_w_sort(a, b, str);
}

void	piv_a(t_d_linklst *a, t_d_linklst *b, char **str)
{
	t_d_linklst *c;

	a->i = 0;
	c = a->flag == 0 ? ft_list_dup(a) : ft_list_dup_to(a);
	quick_sort(c->head, c->tail);
	a->med = find_median(c);
	a->count = count_small(c, a->med);
	while (a->count > 0)
	{
		if (a->head->value < a->med)
		{
			pb(a, b, str);
			a->n_size--;
			a->count--;
		}
		else
		{
			ra(a, str);
			a->i++;
		}
	}
	if (c)
		del_list(c);
	piv_a1(a, b, str, a->i);
}

void	piv_b1(t_d_linklst *a, t_d_linklst *b, char **str, int i)
{
	while (i > 0 && a->fack != 1)
	{
		rrb(b, str);
		i--;
	}
	a->fack = 0;
	r_w_sort(a, b, str);
}

void	piv_b(t_d_linklst *a, t_d_linklst *b, char **str)
{
	initial(a, b);
	if (a->size + b->size == a->f_size)
		a->fack = 1;
	while (b->count > 0)
	{
		if (b->head->value >= b->med)
		{
			pa(a, b, str);
			a->n_size++;
			b->count--;
		}
		else
		{
			rb(b, str);
			b->i++;
		}
	}
	piv_b1(a, b, str, b->i);
}

void	r_w_sort(t_d_linklst *a, t_d_linklst *b, char **str)
{
	bum(a, b, str);
	if (a->size > 2 && !is_sort(a))
		piv_a(a, creat(), str);
	if (b->size > 2 && !is_sort_b(b))
		piv_b(a, b, str);
	move_to_a(a, b, str);
}
