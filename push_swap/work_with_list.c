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
	tmp->flag = 0;
	tmp->fack = 0;
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

void            push_head(t_d_linklst *dest, t_d_linklst *src)
{
	t_node  *tmp;
	t_node	*p;

	tmp = src->head;
	if (src->size > 1)
	{
		p = src->head->next;
		p->prev = NULL;
		src->head = p;
		tmp->next = NULL;
		tmp->prev = NULL;
	}
	if (dest->head == NULL)
		dest->head = tmp;
	else 
	{
		p = dest->head;
		p->prev = tmp;
		tmp->next = p;
		tmp->prev = NULL;
		dest->head = tmp;
	}
	if (dest->tail == NULL)
		dest->tail = tmp;
	src->size--;
	dest->size++;
	if (src->size == 0)
	{
		src->head = NULL;
		src->tail = NULL;
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
		ft_putnbr((int)tmp->value);
		write(1, " ", 1);
		tmp = tmp->next;
	}
	write(1, "\n", 1);
}
