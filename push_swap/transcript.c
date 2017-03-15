/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transcript.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okres <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 14:00:52 by okres             #+#    #+#             */
/*   Updated: 2017/03/15 15:03:34 by okres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	route(char **str, int tmp)
{
	tmp = (*str)[1] - '0';
	if (tmp == 7)
	{
		ft_putstr("rr");
		(*str)++;
	}
	else
		ft_putstr("ra");
	write(1, "\n", 1);
}

void	route1(char **str, int tmp)
{
	tmp = *(str)[1] - '0';
	if (tmp == 6)
	{
		ft_putstr("rr");
		(*str)++;
	}
	else
		ft_putstr("rb");
	write(1, "\n", 1);
}

void	swap(char **str, int tmp)
{
	tmp = (*str)[1] - '0';
	if (tmp == 4)
	{
		ft_putstr("ss");
		(*str)++;
	}
	else
		ft_putstr("sa");
	write(1, "\n", 1);
}

void	swap1(char **str, int tmp)
{
	tmp = (*str)[1] - '0';
	if (tmp == 3)
	{
		ft_putstr("ss");
		(*str)++;
	}
	else
		ft_putstr("sb");
	write(1, "\n", 1);
}

void	optimize(char *str)
{
	int		tmp;
	size_t	count;

	count = 0;
	while (*str)
	{
		tmp = *str - '0';
		if (tmp == 3)
			swap(&str, tmp);
		else if (tmp == 4)
			swap1(&str, tmp);
		else if (tmp == 6)
			route(&str, tmp);
		else if (tmp == 7)
			route1(&str, tmp);
		else if (tmp == 0)
			revers(&str, tmp);
		else if (tmp == 9)
			revers1(&str, tmp);
		else if (tmp == 1 || tmp == 2)
			push_a_and_b(&str, tmp);
		str++;
		count++;
	}
	//ft_putstr("COUNT = ");
	//ft_putnbr((int)count);
	//ft_putstr("\n");
}
