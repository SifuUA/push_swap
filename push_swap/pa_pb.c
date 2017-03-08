#include "push_swap.h"

void	pa(t_d_linklst *list_a, t_d_linklst *list_b, char **str)
{
	char	*p;

	if (list_b->size == 0)
		return ;
	push_head(list_a, list_b);
	p = *str;
	*str = ft_strjoin(p, "pa");
	ft_strdel(&p);
}

void	pb(t_d_linklst *list_a, t_d_linklst *list_b, char **str)
{
	char	*p;

	if (list_a->size == 0)
		return ;
	push_head(list_b, list_a);
	p = *str;
	*str = ft_strjoin(p, "pb");
	ft_strdel(&p);
}

