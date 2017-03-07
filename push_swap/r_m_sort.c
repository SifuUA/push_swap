#include "push_swap.h"


void	piv_a(t_d_linklst *a, t_d_linklst *b)
{
	t_d_linklst *c;
	T			med;
	T 		count;

	c = ft_list_dup(a);
	quick_sort(c->head, c->tail);
	med = find_median(c);
	count = count_small(a, med);
	while (count > 0 && !is_sort(a))
	{
        if (a->size == 3)
        {
            sort_three(a);
            continue;
        }
		if (a->head->value < med)
		{
			//little_help_b(b);
		//	check_1(b);
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
}

void	piv_b(t_d_linklst *a, t_d_linklst *b)
{
	t_d_linklst *c;
	T			med;
	T 			count;
	T 			i;

	i = 0;
	c = ft_list_dup(b);
	quick_sort(c->head, c->tail);
	med = find_median(c);
	count = count_large(b, med);
	//check_1(b);
	while (count >= 0)
	{
		little_help_b(b);
		if (b->head->value >= med /*&& if_biggest(b, b->head->value)*/)
		{
			//little_help(a, b);
			//check_1(b);
			pa(a, b);
			little_help(a, b);
			count--;
		}
		else
		{
			if (search(b, i, b->head->value))
			{
				while (i > 0)
				{
					rrb(b);
					i--;
				}
			}
			else if (a->size + b->size == a->f_size)
			{
					if (most_close_max(b, med))
					{
						while (!if_biggest(b, b->head->value))
							rrb(b);
					}
					else
						rb(b);
			}
			else
			{
					rb(b);
					i++;
			}
		}

	}
	while (i > 0 && a->size + b->size != a->f_size)
	{
		rrb(b);
		i--;
	}
	r_w_sort(a, b);
}

void	r_w_sort(t_d_linklst *a, t_d_linklst *b)
{
	if (a->size > 2 && !is_sort(a))
		piv_a(a, (t_d_linklst *)malloc(sizeof(t_d_linklst)));
	if (b->size > 2 && !is_sort(b))
		piv_b(a, b);
	move_to_a(a, b);
}
