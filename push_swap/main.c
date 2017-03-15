/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okres <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 13:11:05 by okres             #+#    #+#             */
/*   Updated: 2017/03/15 13:15:51 by okres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		find_same(long int num, t_d_linklst *list)
{
	t_node	*tmp;

	tmp = list->head;
	while (tmp)
	{
		if (tmp->value == num)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

static void		write_in_list(t_d_linklst *list, char **s)
{
	long int	i;
	long int	tmp;

	i = 1;
	tmp = 0;
	while (s[i])
	{
		tmp = ft_atoi(s[i]);
		if (ft_strcmp(ft_itoa((int)tmp), s[i]) == 0 &&
				find_same(tmp, list) == 0)
			push_front(list, tmp);
		else
		{
			write(2, "Error", 5);
			exit(WRONG_ARG);
		}
		i++;
	}
}

int				main(int argc, char **argv)
{
	t_d_linklst		*list_a;
	t_d_linklst		*list_b;
	char			*str;

	str = ft_strnew(5000);
	list_a = creat();
	list_b = creat();
	if (argc > 1)
	{
		write_in_list(list_a, argv);
		list_a->f_size = list_a->size;
		if (list_a->f_size <= 100)
			do_it_shit(list_a, list_b, &str);
		else
			r_w_sort(list_a, list_b, &str);
		optimize(str);
	}
	else
		write(1, "\n", 1);
	ft_strdel(&str);
	del_list(list_a);
	return (0);
}
