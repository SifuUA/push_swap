#include "push_swap.h"

static int      find_same(T num, t_d_linklst *list)
{
	t_node  *tmp;

	tmp = list->head;
	while (tmp)
	{
		if (tmp->value == num)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

static void     write_in_list(t_d_linklst *list, char **s)
{
	T   i;
	T   tmp;

	i = 1;
	tmp = 0;
	while (s[i])
	{
		tmp = ft_atoi(s[i]);
		if (ft_strcmp(ft_itoa((int)tmp), s[i]) == 0 && find_same(tmp, list) == 0)
			push_front(list, tmp);
		else
		{
			write(2, "Error", 5);
			exit(WRONG_ARG);
		}
		i++;
	}
}

int             main(int argc, char **argv)
{
	t_d_linklst     *list_a;
	t_d_linklst     *list_b;
	size_t 			len;
	char 			*str;

	str = ft_strnew(5000);
	list_a = creat();
	list_b = creat();
	if (argc > 1)
	{
		write_in_list(list_a, argv);
		printList(list_a);
		list_a->f_size = list_a->size;
		int i = 0;
		/*while ( i < 1)
		{
			ra(list_a, &str);
			i++;
		}*/
		r_w_sort(list_a, list_b, &str);
		optimize(str);
		printList(list_a);
	}
	else
		write(1, "\n", 1);
	del_list(list_a);
	return (0);
}