/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_help.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okres <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 12:55:39 by okres             #+#    #+#             */
/*   Updated: 2017/03/15 12:58:43 by okres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra_mod(t_d_linklst *list)
{
	t_node	*tmp;

	if (list->size > 1)
	{
		tmp = list->head;
		list->head = tmp->next;
		tmp->prev = list->tail;
		tmp->next = NULL;
		list->tail->next = tmp;
		list->tail = tmp;
	}
}

void	mod(t_d_linklst *new, int i, int f)
{
	if (f == 1)
	{
		while (i > 0)
		{
			ra_mod(new);
			i--;
		}
	}
	else if (f == 2)
	{
		while (i > 0)
		{
			rra_mod(new);
			i--;
		}
	}
}

void	tell_me_1(char *tmp, t_d_linklst *l, char *str)
{
	if ((str[l->i] - '0' == 9 && str[l->i + 1] - '0' == 0) ||
			(str[l->i] - '0' == 0 && str[l->i + 1] - '0' == 9))
	{
		tmp[l->j] = 8;
		l->i += 2;
		l->j++;
	}
	else
	{
		tmp[l->j] = str[l->i];
		l->j++;
		l->i++;
	}
}

size_t	analize(size_t *arr, size_t des)
{
	int		i;
	size_t	res;
	size_t	j;
	size_t	min_ra;

	i = 0;
	j = 0;
	res = 0;
	min_ra = arr[i] + i;
	while (i < des)
	{
		j = arr[i] + i;
		if (min_ra > j)
		{
			min_ra = j;
			res = (size_t)i;
		}
		i++;
	}
	return (res);
}

char	*tell_me(t_d_linklst *l, char *str)
{
	char	*tmp;

	l->i = 0;
	l->j = 0;
	tmp = ft_strnew(ft_strlen(str));
	while (str[l->i])
	{
		if ((str[l->i] - '0' == 6 && str[l->i + 1] - '0' == 7) ||
				(str[l->i] - '0' == 7 && str[l->i + 1] - '0' == 6))
		{
			tmp[l->j] = 8;
			l->i += 2;
			l->j++;
		}
		else if ((str[l->i] - '0' == 3 && str[l->i + 1] - '0' == 4) ||
				(str[l->i] - '0' == 4 && str[l->i + 1] - '0' == 3))
		{
			tmp[l->j] = 5;
			l->i += 2;
			l->j++;
		}
		else
			tell_me_1(tmp, l, str);
	}
	return (tmp);
}
