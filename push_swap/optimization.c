#include "push_swap.h"

void	route(char *str, int i, int tmp)
{

	tmp = str[i + 1] - '0';
	if (tmp == 7)
		ft_putstr("rr");
	else
		ft_putstr("ra");
	write(1, "\n", 1);
}

void	route1(char *str, int i, int tmp)
{

	tmp = str[i + 1] - '0';
	if (tmp == 6)
		ft_putstr("rr");
	else
		ft_putstr("rb");
	write(1, "\n", 1);
}
void	swap(char **str, int i, int tmp)
{

	tmp = (*str)[i + 1] - '0';
	if (tmp == 4)
	{
		ft_putstr("ss");
		(*str)++;
	}
	else
		ft_putstr("sa");
	write(1, "\n", 1);
}

void	swap1(char **str, int i, int tmp)
{

	tmp = (*str)[i + 1] - '0';
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
	int i;
	int tmp;

	i = 0;
	while (str[i])
	{
		tmp = str[i] - '0';
		if (tmp == 3)
			swap(&str, i, tmp);
		else if (tmp == 4)
			swap1(&str, i, tmp);
		else if (tmp == 6)
			route(str, i, tmp);
		else if (tmp == 7)
			route1(str, i, tmp);
		else if (tmp == 0)
			revers(str, tmp, i);
		else if (tmp == 9)
			revers1(str, tmp, i);
		else
		{
			write(1, &str[i], 2);
			write(1, "\n", 1);
			str++;
		}
		str++;
	}
}
