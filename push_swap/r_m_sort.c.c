#include "push_swap.h"


void	piv_a(t_d_linklst *a, t_d_linklst *b)
{
	t_d_linklst *c;
	T			med;
	size_t 		count;
	t_node		*tmp;

	c = ft_list_dup(a);
	quick_sort(c->head, c->tail);
	med = find_median(c);
	count = count_small(a, med);
	tmp = a->head;
	while (count > 0)
	{
		if (a->head->value < med)
		{
			pb(a, b);
			count--;
		}
		else
			ra(a);
	}
	r_w_sort(a, b);
}

void	piv_b(t_d_linklst *a, t_d_linklst *b)
{
	t_d_linklst *c;
	T			med;
	size_t 		count;
	t_node		*tmp;

	c = ft_list_dup(a);
	quick_sort(c->head, c->tail);
	med = find_median(c);
	count = count_small(a, med);
	tmp = a->head;
	while (count > 0)
	{
		if (a->head->value < med)
		{
			pb(a, b);
			count--;
		}
		else
			ra(a);
	}
	r_w_sort(a, b);
}

void	r_w_sort(t_d_linklst *a, t_d_linklst *b)
{
	if (a->size > 2)
		piv_a(a, (t_d_linklst *)malloc(sizeof(t_d_linklst)));
	if (b->size > 2)
		piv_b(b,(t_d_linklst *)malloc(sizeof(t_d_linklst)));
	else
		replace_to_a(a, b);
}