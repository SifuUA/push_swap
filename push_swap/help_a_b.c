#include "push_swap.h"

void	little_help(t_d_linklst *list_a, t_d_linklst *list_b)
{
	//if (list_b->head != NULL && list_b->size > 1 && list_b->head->value < list_b->head->next->value)
	//	sb(list_b);
	if (list_a->head != NULL && list_a->size > 1 && list_a->head->value > list_a->head->next->value)
		sa(list_a);
}

void	little_help_b(t_d_linklst *list_b)
{
	if (list_b->head != NULL && list_b->size > 1 && list_b->head->value < list_b->head->next->value)
		sb(list_b);
}

void    move_to_a(t_d_linklst *list_a, t_d_linklst *list_b)
{
	check_1(list_b);
	while (list_b->size > 0)
	{
		little_help(list_a, list_b);
		pa(list_a, list_b);
		little_help(list_a, list_b);
	}
}

int 	most_close_min(t_d_linklst *list, T med)
{
	t_node	*tmp;
	int 	i;

	tmp = list->head;
	i = 1;
	while (tmp)
	{
		if (tmp->value < med)
			return (i);
		i++;
		tmp = tmp->next;
	}
	return (0);
}

int 	most_close_max(t_d_linklst *list, T med)
{
	t_node	*tmp;
	int 	i;
	int 	j;

	tmp = list->head;
	i = 1;
	j = 1;
	while (tmp)
	{
		if (if_biggest(list, tmp->value))
			break ;
		i++;
		tmp = tmp->next;
	}
	tmp = list->tail;
	while (tmp)
	{
		if (if_biggest(list, tmp->value))
			break ;
		j++;
		tmp = tmp->prev;
	}
	return (i <= j ? 0 : 1);
}

void    optimize_check(t_d_linklst *list)
{
	if (list->head > list->head->next)
		sa(list);
	else if (list->tail < list->tail->prev && list->tail > list->head)
	{
		rra(list);
		rra(list);
		sa(list);
		ra(list);
		ra(list);
	}
	else if (list->head > list->head->next && list->tail < list->head)
		ra(list);
	else if (list->tail < list->head && list->tail < list->tail->prev)
		rra(list);
}

void	check_1(t_d_linklst *b)
{
	if (b->size >= 3)
	{
		if (b->head->next->value < b->head->next->next->value &&
				b->head->next->next->value > b->head->value &&
				b->head->value > b->head->next->value)
		{
			rb(b);
			sb(b);
			rrb(b);
			sb(b);
		}
		else if (b->head->value < b->head->next->value &&
				b->head->next->value < b->head->next->next->value)
		{
			sb(b);
			rb(b);
			sb(b);
			rrb(b);
			sb(b);
		}
		else if (b->head->value < b->head->next->value &&
				b->head->next->next->value < b->head->next->value &&
				b->head->next->next->value > b->head->value)
		{
			sb(b);
			rb(b);
			sb(b);
			rrb(b);
		}
		else if (b->head->value > b->head->next->value &&
				b->head->value > b->head->next->next->value &&
				b->head->next->value < b->head->next->next->value)
		{
			rb(b);
			sb(b);
			rrb(b);
		}
		else if (b->head->value < b->head->next->value)
			sb(b);
	}
}

/*void    check_2(t_d_linklst *list)
{

	if (list->tail->value < list->tail->prev->value && list->tail->value > list->head->value)
	{
		rra(list);
		rra(list);
		sa(list);
		ra(list);
		ra(list);
	}
	else if (list->head->value > list->head->next->value && list->tail->value < list->head->value)
		ra(list);
	else if (list->tail->value < list->head->value && list->tail->value < list->tail->prev->value)
		rra(list);
	else if (list->head->value > list->head->next->value)
		sa(list);
}*/

void	check_2(t_d_linklst *a)
{
	if (a->size >= 3)
	{

		if (a->head->value < a->head->next->value &&
				 a->head->next->next->value < a->head->next->value &&
				 a->head->next->next->value > a->head->value)
		{
			sa(a);
			ra(a);
			rra(a);
		}
		else if (a->head->value > a->head->next->value &&
				 a->head->value > a->head->next->next->value &&
				 a->head->next->value < a->head->next->next->value)
		{
			sa(a);
			ra(a);
			sa(a);
			rra(a);
		}
		else if (a->head->next->value < a->head->next->next->value &&
					 a->head->next->next->value > a->head->value &&
					 a->head->value > a->head->next->value)
		{
			sa(a);
		}
		else if (a->head->value < a->head->next->value)
			sa(a);
	}
}

int 	if_biggest(t_d_linklst *l, T val)
{
	t_node	*tmp;
	T 		biggest;

	tmp = l->head;
	biggest = tmp->value;
	while (tmp)
	{
		if(tmp->value > biggest)
			biggest = tmp->value;
		tmp = tmp->next;
	}
	return (biggest == val ? 1 : 0);
}

int 	search(t_d_linklst *l, T count, T val)
{
	t_node	*p;

	p = l->tail;
	while (count > 0)
	{
		if (if_biggest(l, p->value))
			return (1);
		count--;
		p = p->prev;
	}
	return (0);
}