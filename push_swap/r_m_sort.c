#include "push_swap.h"


void	piv_a(t_d_linklst *a, t_d_linklst *b, char **str)
{
	t_d_linklst *c;
	T			med;
	T 		count;
	int 		i;


	i = 0;
	c = a->flag == 0 ? ft_list_dup(a) : ft_list_dup_to(a);
	quick_sort(c->head, c->tail);
	med = find_median(c);
	count = count_small(a, med);
	while (count > 0 && !is_sort(a))
	{
        if (a->size == 3)
        {
            sort_three(a, str);
            continue;
        }
		if (a->head->value < med)
		{
			//little_help_b(b);
		//	check_1(b);
			pb(a, b, str);
			count--;
		}
		else
		{
			ra(a, str);
			i++;
		}
	}
	if (a->flag != 0)
	{
		while (i > 0)
		{
			rra(a, str);
			little_help(a, b, str);
			i--;
		}
	}
	r_w_sort(a, b, str);
}

void	piv_b(t_d_linklst *a, t_d_linklst *b, char **str)
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
	check_1(b, str);
	a->flag = 1;
	while (count >= 0)
	{
		//little_help_b(b, str);
		if (b->head->value >= med /*&& if_biggest(b, b->head->value)*/)
		{
			//little_help(a, b);
			//check_1(b);
			pa(a, b, str);
			little_help(a, b, str);
			count--;
		}
		else
		{
			/*if (search(b, i, b->head->value))
			{
				while (i > 0)
				{
					rrb(b, str);
					i--;
				}
			}
			else if (a->size + b->size == a->f_size)
			{
					if (most_close_max(b, med))
					{
						while (!if_biggest(b, b->head->value))
							rrb(b, str);
					}
					else

						rb(b, str);
			}
			else
			{*/
					rb(b, str);
					i++;
			//}
		}

	}
	while (i > 0 && a->size + b->size != a->f_size)
	{
		rrb(b, str);
		i--;
	}
	r_w_sort(a, b, str);
}

void	r_w_sort(t_d_linklst *a, t_d_linklst *b, char **str)
{
	if (a->size > 2 && !is_sort(a))
		piv_a(a, (t_d_linklst *)malloc(sizeof(t_d_linklst)), str);
	if (b->size > 2)
		piv_b(a, b, str);
	move_to_a(a, b, str);
}
