#include "push_swap.h"


void	piv_a(t_d_linklst *a, t_d_linklst *b)
{
	t_d_linklst *c;
	T			med;
	size_t 		count;

	c = ft_list_dup(a);
	quick_sort(c->head, c->tail);
	med = find_median(c);
	count = count_small(a, med);
	check_2(a);
	while (count > 0 && !is_sort(a))
	{
		//check_2(a);
		if (a->head->value < med)
		{
			pb(a, b);
			count--;
		}
		else
		{
			if (most_close_min(a, med) > a->size / 2)// проблема вибору серед 3 чисел
				rra(a);
			else
				ra(a);
		}
	}
	r_w_sort(a, b);
	move_to_a(a, b);
}

void	piv_b(t_d_linklst *a, t_d_linklst *b)
{
	t_d_linklst *c;
	T			med;
	T 			count;

	c = ft_list_dup(b);
	quick_sort(c->head, c->tail);
	med = find_median(c);
	count = count_large(b, med);
	check_1(b);
	while (count >= 0)
	{
		if (b->head->value >= med)
		{
			check_1(b);
			pa(a, b);
			little_help(a, b);
			count--;
		}
		else
		{
			if (most_close_max(a, med) > a->size / 2)// проблема вибору серед 3 чисел
				rrb(b);
			else
				rb(b);
		}
	}
	r_w_sort(a, b);
	move_to_a(a, b);
}

void	r_w_sort(t_d_linklst *a, t_d_linklst *b)
{
	if (a->size > 2 && !is_sort(a))
		piv_a(a, (t_d_linklst *)malloc(sizeof(t_d_linklst)));
	if (b->size > 2 && !is_sort(b))
		piv_b(a, b);
}