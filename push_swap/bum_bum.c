#include "push_swap.h"

void	sort_three_down(t_d_linklst *a, char **str)
{
	if (a->size == 2)
	{
		if (a->head->value > a->head->next->value)
			sa(a, str);
	}
	if (a->head->value > a->head->next->value &&
		a->head->value < a->tail->value)
		sa(a, str);
	else if (a->head->value > a->head->next->value &&
			 a->tail->value > a->tail->prev->value)
		ra(a, str);
	else if (a->tail->value < a->tail->prev->value &&
			 a->tail->value < a->head->value)
	{
		sa(a, str);
		rra(a, str);
	}
	else if (a->head->value > a->tail->value &&
			 a->tail->value < a->tail->prev->value)
	{
		sa(a, str);
		rra(a, str);
	}
	else if (a->head->value < a->tail->value &&
			 a->tail->value < a->tail->prev->value)
	{
		rra(a, str);
		sa(a, str);
	}
}

void 	sort_two(t_d_linklst *l, char **str)
{
	if (l ->size > 1)
	{
		if (l->head->value < l->head->next->value)
			sb(l,str);
	}
}

void	sort_four(t_d_linklst *a, t_d_linklst *b, char **str)
{
	T 	num;
	t_d_linklst *c;
	int 	i;
	int		f;

	i = 0;
	c = ft_list_dup(a);
	quick_sort(c->head, c->tail);
	num = c->head->value;
	f = a->size != (a->f_size + a->n_size) ? 1 : 0;
	if (!is_sort(a))
	{
		while (a->head->value != num)
		{
			if (f == 0)
			{
				if (a->tail->value == num)
					rra(a, str);
				else
					ra(a, str);
			}
			else
				ra(a, str);// можно убрать пару операций ра или рра
			i++;
		}
		pb(a, b, str);
		while (i > 0 && f != 0) // добавил условие
		{
			rra(a, str);
			i--;
		}
		f == 1 ? check_2(a, str) : check_3(a, str);
		pa(a, b, str);
	}
	if (!is_sort_b(b))
		b->size == 3 ? check_1(b, str) : sort_two(b, str);
}

void	pum(t_d_linklst *a, t_d_linklst *b, char **str)
{
	if (a->n_size > 1 && a->head->value > a->head->next->value)
		sa(a, str);
	if (b->size > 1 && b->head->value < b->head->next->value)
		sb(b, str);
	if (a->n_size > 1 && a->i == 1)
		rra(a, str);
	if (b->size > 1 && a->j == 1)
		rrb(b, str);
	if (a->n_size > 1 && a->head->value > a->head->next->value)
		sa(a, str);
	if (b->size > 1 && b->head->value < b->head->next->value)
		sb(b, str);
}

void	bum(t_d_linklst *a, t_d_linklst *b, char **str)
{
	a->i = 0;
	a->j = 0;

	if ((a->size == 4 || a->n_size == 4) && b->size <= 3 && !is_sort(a))
	{
		sort_four(a, b, str);
		return ;
	}
	else if (a->size <= 3 && b->size <= 3 && a->n_size <= 0)
		sort_three_down(a, str);
	if (a->n_size <= 3 && b->size <= 3)
	{
		if (a->n_size > 1 && a->head->value > a->head->next->value)
			sa(a, str);
		if (b->size > 1 && b->head->value < b->head->next->value)
			sb(b, str);
		if (a->n_size > 1 && !is_sort(a))
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
