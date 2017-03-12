#include "push_swap.h"

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

void 	mod(t_d_linklst *new, int i)
{
	while (i > 0)
	{
		ra_mod(new);
		i--;
	}
}

void 	analize(size_t *arr, int des)
{
	int	i;
	int res;
	size_t j;
	size_t  min;

	i = 0;
	j = 0;
	res = 0;
	min = arr[i] + i;
	while (arr[i] && i < des)
	{
		j = arr[i] + i;;
		if (min > j)
		{
			min = j;
			res = i;
		}
		i++;
	}
}
void 	choose(t_d_linklst *a, t_d_linklst *b, char **str)
{
	int 		i;
	size_t 		size;
	size_t 		arr[a->size / 2];
	t_d_linklst	*new;

	i = 0;
	size = a->size / 2;
	new = ft_list_dup(a);
	r_w_sort(new, b, str);
	del_list(new);
	arr[i] = ft_strlen(*str);
	i++;
	while (i < size)
	{
		new = ft_list_dup(a);
		mod(new, i);
		r_w_sort(new, b, str);
		del_list(new);
		arr[i] = ft_strlen(*str);
		ft_bzero(*str, arr[i]);
		i++;
	}
	analize(arr, i);
}

