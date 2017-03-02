#include "push_swap.h"

t_d_linklst     *creat(void) // создание листа
{
	t_d_linklst *tmp;
	int 		i;

	i = 0;
	tmp = (t_d_linklst *)malloc(sizeof(t_d_linklst));
	tmp->size = 0;
	tmp->head = NULL;
	tmp->tail = NULL;
	/*tmp->ar = malloc(sizeof(size_t) * 1000);
	while (i < 1000)
	{
		tmp->ar[i] = 0;
		i++;
	}*/
	return (tmp);
}

void            push_front(t_d_linklst *list, int value)
{
	t_node  *node;

	node = (t_node *)malloc(sizeof(t_node));
	if (node == NULL)
		exit(OUT_OF_MEM);
	node->value = value;
	node->next = NULL;
	node->prev = list->tail;
	if (list->tail)
		list->tail->next = node;
	list->tail = node;
	if (list->head == NULL)
		list->head = node;
	list->size++;
}

void            push_head(t_d_linklst *list1, t_d_linklst *list2)
{
	t_node  *tmp;

	tmp = list2->head;
	if (list2->size > 1)
	{
		list2->head->next->prev = NULL;
		list2->head = list2->head->next;
	}
	tmp->prev = NULL;
	tmp->next = NULL;
	if (list1->head == NULL)
		list1->head = tmp;
	else
	{
		list1->head->prev = tmp;
		tmp->next = list1->head;
		tmp->prev = NULL;
		list1->head = tmp;
	}
	if (list1->tail == NULL)
		list1->tail = tmp;
	list2->size--;
	list1->size++;
	if (list2->size == 0)
	{
		list2->head = NULL;
		list2->tail = NULL;
	}
}
void 			del_list(t_d_linklst *list)
{
	t_node	*tmp;

	while (list->head)
	{
		tmp = list->head;
		list->head = list->head->next;
		free(tmp);
	}
}

void            printList(t_d_linklst *list)
{
	t_node  *tmp;

	tmp = list->head;
	while (tmp)
	{
		ft_putnbr(tmp->value);
		write(1, " ", 1);
		tmp = tmp->next;
	}
	write(1, "\n", 1);
}
