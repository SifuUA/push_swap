#include "push_swap.h"

void	pum(t_d_linklst *a, t_d_linklst *b, char **str)
{
	if (a->size > 1 && a->head->value > a->head->next->value)
		sa(a, str);
	if (b->size > 1 && b->head->value < b->head->next->value)
		sb(b, str);
	if (a->size > 1 && a->i == 1)
		rra(a, str);
	if (b->size > 1 && a->j == 1)
		rrb(b, str);
	if (a->size > 1 && a->head->value > a->head->next->value)
		sa(a, str);
	if (b->size > 1 && b->head->value < b->head->next->value)
		sb(b, str);
}

void	bum(t_d_linklst *a, t_d_linklst *b, char **str)
{
	a->i = 0;
	a->j = 0;

	if (a->size <= 3 && b->size <= 3)
	{
		if (a->size > 1 && a->head->value > a->head->next->value)
			sa(a, str);
		if (b->size > 1 && b->head->value < b->head->next->value)
			sb(b, str);
		if (a->size > 1 && !is_sort(a))
		{
			ra(a, str);
			a->i++;
		}
		if (b->size > 1 && !is_sort_b(b))
		{
			rb(b, str);
			a->j++;
		}
		pum(a, b, str);
	}
}
