#include "push_swap.h"

size_t	analize2(size_t *arr, size_t des)
{
	int i;
	size_t j;
	size_t  min_ra;

	i = 0;
	j = 0;
	min_ra = arr[i] + i;
	while (i < des)
	{
		j = arr[i] + i;
		if (min_ra > j)
			min_ra = j;
		i++;
	}
	return (min_ra);
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
	arr_rra[i] = ft_strlen(tell_me(a, *str));
	i++;
	while (i < size)
	{
		new = ft_list_dup(a);
		mod(new, i, 2);
		r_w_sort(new, b, str);
		del_list(new);
		arr_rra[i] = ft_strlen(tell_me(a, *str));
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


	i = 0;
	size = a->size / 2;
	new = ft_list_dup(a);
	r_w_sort(new, b, str);
	del_list(new);
	arr_ra[i] = ft_strlen(tell_me(a, *str));
	i++;
	while (i < size)
	{
		new = ft_list_dup(a);
		mod(new, i, 1);
		r_w_sort(new, b, str);
		del_list(new);
		arr_ra[i] = ft_strlen(tell_me(a, *str));
		ft_bzero(*str, arr_ra[i]);
		i++;
	}
	ptr = arr_ra;
	return (ptr);
}

void 	do_it_shit(t_d_linklst *a, t_d_linklst *b, char **str)
{
	size_t 	ret_ra;
	size_t 	ret_rra;
	size_t 	*ar_1;
	size_t 	*ar_2;
	size_t  tmp;
	size_t  tmp2;


	ar_1 = choose(a, b, str);
	ret_ra = analize(ar_1, a->size / 2 );
	tmp = analize2(ar_1, a->size / 2);
	ar_2 = choose2(a, b, str);
	ret_rra = analize(ar_2, a->size / 2 );
	tmp2 = analize2(ar_2, a->size / 2);
	if (tmp < tmp2)
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

