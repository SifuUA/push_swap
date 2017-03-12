#include "push_swap.h"

char 	*tell_me(char *str)
{
	int i;
	int j;
	char *tmp;

	i = 0;
	j = 0;
	tmp = ft_strnew(ft_strlen(str));
	while (str[i])
	{
		if((str[i] - '0' == 6 && str[i + 1] - '0' == 7) ||
				(str[i] - '0' == 7 && str[i + 1] - '0' == 6))
		{
			tmp[j] = 8;
			i += 2;
			j++;
		}
		else if ((str[i] - '0' == 3 && str[i + 1] - '0' == 4) ||
				(str[i] - '0' == 4 && str[i + 1] - '0' == 3))
		{
			tmp[j] = 5;
			i += 2;
			j++;
		}
		else if ((str[i] - '0' == 9 && str[i + 1] - '0' == 0) ||
				 (str[i] - '0' == 0 && str[i + 1] - '0' == 9))
		{
			tmp[j] = 8;
			i += 2;
			j++;
		}
		else
		{
			tmp[j] = str[i];
			j++;
			i++;
		}
	}
	return (tmp);
}

void 	ra_mod(t_d_linklst *list)
{
	t_node	*tmp;

	if (list->size > 1)
	{
		tmp = list->head;
		list->head = tmp->next;
		tmp->prev = list->tail;
		tmp->next = NULL;
		list->tail->next = tmp;
		list->tail = tmp;
	}
}

void 	mod(t_d_linklst *new, int i, int f)
{
	if (f == 1)
	{
		while (i > 0) {
			ra_mod(new);
			i--;
		}
	}
	else if (f == 2)
	{
		while (i > 0) {
			rra_mod(new);
			i--;
		}
	}
}

int		analize(size_t *arr, size_t des)
{
	int i;
	int res;
	size_t j;
	size_t  min_ra;

	i = 0;
	j = 0;
	min_ra = arr[i] + i;
	res = 0;
	while (i < des)
	{
		j = arr[i] + i;;
		if (min_ra > j)
		{
			min_ra = j;
			res = i;
		}
		i++;
	}
	return (res);
}

size_t 	*choose2(t_d_linklst *a, t_d_linklst *b, char **str)
{
	int 		i;
	size_t 		size;
	size_t 		arr_rra[a->size / 2];
	t_d_linklst	*new;
	size_t 		*ptr;

	i = 0;
	ptr = arr_rra;
	size = a->size / 2;
	new = ft_list_dup(a);
	r_w_sort(new, b, str);
	del_list(new);
	arr_rra[i] = ft_strlen(*str);
	i++;
	while (i < size)
	{
		new = ft_list_dup(a);
		mod(new, i, 2);
		r_w_sort(new, b, str);
		del_list(new);
		arr_rra[i] = ft_strlen(tell_me(*str));
		ft_bzero(*str, arr_rra[i]);
		i++;
	}
	return (ptr);
}

size_t	*choose(t_d_linklst *a, t_d_linklst *b, char **str)
{
	int 		i;
	size_t 		size;
	size_t 		arr_ra[a->size / 2];
	t_d_linklst	*new;
	size_t 		*ptr;

	ptr = arr_ra;
	i = 0;
	size = a->size / 2;
	new = ft_list_dup(a);
	r_w_sort(new, b, str);
	del_list(new);
	arr_ra[i] = ft_strlen(*str);
	i++;
	while (i < size)
	{
		new = ft_list_dup(a);
		mod(new, i, 1);
		r_w_sort(new, b, str);
		del_list(new);
		arr_ra[i] = ft_strlen(tell_me(*str));
		ft_bzero(*str, arr_ra[i]);
		i++;
	}

	return (ptr);
}

void 	do_it_shit(t_d_linklst *a, t_d_linklst *b, char **str)
{
	int 	ret_ra;
	int 	ret_rra;
	size_t 	*ar_1;
	size_t 	*ar_2;

	ar_1 = choose(a, b, str);
	ar_2 = choose2(a, b, str);
	ret_ra = analize(ar_1, a->size / 2 );
	ret_rra = analize(ar_2, a->size / 2 );
	if (ar_1[ret_ra] + ret_ra < ar_2[ret_rra] + ret_rra)
	{
		while (ret_ra > 0)
		{
			ra(a, str);
			ret_ra--;
		}
		r_w_sort(a, b, str);
	}
	else
	{
		while (ret_rra > 0)
		{
			rra(a, str);
			ret_rra--;
		}
		r_w_sort(a, b, str);
	}
}

