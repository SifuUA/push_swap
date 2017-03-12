#include "push_swap.h"

void	revers(char **str, int tmp)
{

	tmp = (*str)[1] - '0';
	if (tmp == 9)
	{
		ft_putstr("rrr");
		(*str)++;
	}
	else
		ft_putstr("rrb");
	write(1, "\n", 1);
}

void	revers1(char **str, int tmp)
{
	tmp = (*str)[1] - '0';
	if (tmp == 0)
	{
		ft_putstr("rrr");
		(*str)++;
	}
	else
		ft_putstr("rra");
	write(1, "\n", 1);
}

void 	push_a_and_b(char **str, int tmp)
{
	if (tmp == 1)
		ft_putstr("pa");
	else if (tmp == 2)
		ft_putstr("pb");
	write(1, "\n", 1);
}

