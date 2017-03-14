/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   differ_sorts.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okres <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 21:40:05 by okres             #+#    #+#             */
/*   Updated: 2017/03/14 21:40:31 by okres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_dow_b(t_d_linklst *b, char **str)
{
	if (b->head->next->value < b->head->next->next->value &&
		b->head->next->next->value > b->head->value &&
		b->head->value > b->head->next->value)
		rrb(b, str);
	else if (b->head->value < b->head->next->value &&
			b->head->next->value < b->head->next->next->value)
	{
		rb(b, str);
		sb(b, str);
	}
	else if (b->head->value < b->head->next->value &&
			b->head->next->next->value < b->head->next->value &&
			b->head->next->next->value > b->head->value)
		rb(b, str);
	else if (b->head->value > b->head->next->value &&
			b->head->value > b->head->next->next->value &&
			b->head->next->value < b->head->next->next->value)
	{
		sb(b, str);
		rb(b, str);
	}
	else if (b->head->value < b->head->next->value)
		sb(b, str);
}

int		min_s(t_d_linklst *l, char **str)
{
	rra_mod(l);
	if (is_sort(l))
	{
		ra_mod(l);
		rra(l, str);
		return (1);
	}
	ra_mod(l);
	ra_mod(l);
	if (is_sort(l))
	{
		rra_mod(l);
		ra(l, str);
		return (1);
	}
	rra_mod(l);
	sa_mod(l);
	if (is_sort(l))
	{
		sa_mod(l);
		sa(l, str);
		return (1);
	}
	sa_mod(l);
	return (0);
}

void	pum(t_d_linklst *a, t_d_linklst *b, char **str)
{
	if ((a->n_size > 1 || a->size > 1) && a->head->value > a->head->next->value)
		sa(a, str);
	if (b->size > 1 && b->head->value < b->head->next->value)
		sb(b, str);
	if ((a->n_size > 1 || a->size > 1) && a->i == 1)
		rra(a, str);
	if (b->size > 1 && a->j == 1)
		rrb(b, str);
	if ((a->n_size > 1 || a->size > 1) && a->head->value > a->head->next->value)
		sa(a, str);
	if (b->size > 1 && b->head->value < b->head->next->value)
		sb(b, str);
}

void	f_4(t_d_linklst *a, t_d_linklst *b, char **str)
{
	if ((a->n_size > 1 || a->size > 1) && a->head->value > a->head->next->value)
		sa(a, str);
	if (b->size > 1 && b->head->value < b->head->next->value)
		sb(b, str);
	if ((a->n_size > 1 || a->size > 1) && !is_sort(a))
	{
		ra(a, str);
		a->i++;
	}
	if (b->size > 1 && !is_sort_b(b))
	{
		rb(b, str);
		a->j++;
	}
	pum(a, b, str);
}
