#include "push_swap.h"

void	revers(char *str, int i, int tmp)
{

	tmp = str[i + 1] - '0';
	if (tmp == 9)
		ft_putstr("rrr");
	else
		ft_putstr("rrb");
	write(1, "\n", 1);
}

void	revers1(char *str, int i, int tmp)
{

	tmp = str[i + 1] - '0';
	if (tmp == 0)
		ft_putstr("rrr");
	else
		ft_putstr("rra");
	write(1, "\n", 1);
}