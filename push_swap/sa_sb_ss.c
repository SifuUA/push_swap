#include "push_swap.h"

void    sa(t_d_linklst *list_a, char **str)
{
	T 		tmp;
	char	*p;

	if (list_a->size > 1)
	{
		tmp = list_a->head->value;
		list_a->head->value = list_a->head->next->value;
		list_a->head->next->value = tmp;
		p = *str;
		*str = ft_strjoin(p, "3");
		ft_strdel(&p);
	}
}

void    sb(t_d_linklst *list_b, char **str)
{
	T 		tmp;
	char	*p;
	if (list_b->size > 1)
	{
		tmp = list_b->head->value;
		list_b->head->value = list_b->head->next->value;
		list_b->head->next->value = tmp;
		p = *str;
		*str = ft_strjoin(p, "4");
		ft_strdel(&p);
	}
}

void    ss(t_d_linklst *list_a, t_d_linklst *list_b, char **str)
{
	char 	*p;

	p = "";
	sa(list_a, &p);
	sb(list_b, &p);
	p = *str;
	*str = ft_strjoin(p, "ss");
	ft_strdel(&p);
}
