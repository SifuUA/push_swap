/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okres <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 14:15:48 by okres             #+#    #+#             */
/*   Updated: 2017/03/15 14:21:07 by okres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_PUSH_SWAP_H
# define PUSHSWAP_PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

# define OUT_OF_MEM 1
# define WRONG_ARG 2
# define ALREDY_SORT 3

typedef struct		s_node
{
	long int		value;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef struct		s_d_linklst
{
	struct s_node	*head;
	struct s_node	*tail;
	size_t			size;
	size_t			f_size;
	int				flag;
	int				fack;
	int				i;
	int				j;
	int				f;
	int				n_size;
	long int		median;
	long int		num;
	size_t			ret_ra;
	size_t			ret_rra;
	size_t			tmp;
	size_t			tmp2;
	size_t			*ar_1;
	size_t			*ar_2;
	long int		med;
	long int		count;
}					t_d_linklst;

void				sa(t_d_linklst *list_a, char **str);
void				sb(t_d_linklst *list_a, char **str);
void				ss(t_d_linklst *list_a, t_d_linklst *list_b, char **str);
void				pa(t_d_linklst *list_a, t_d_linklst *list_b, char **str);
void				pb(t_d_linklst *list_a, t_d_linklst *list_b, char **str);
void				ra(t_d_linklst *list, char **str);
void				rb(t_d_linklst *list, char **str);
void				rr(t_d_linklst *list_a, t_d_linklst *list_b, char **str);
void				rra(t_d_linklst *list, char **str);
void				rrb(t_d_linklst *list, char **str);
void				rrr(t_d_linklst *list_a, t_d_linklst *list_b, char **str);

t_d_linklst			*creat(void);
void				printlist(t_d_linklst *list);
void				push_front(t_d_linklst *list, int value);
void				push_head(t_d_linklst *list, t_d_linklst *list2);
void				del_list(t_d_linklst *list);

void				push_swap(t_d_linklst *list_a, t_d_linklst *list_b);
int					is_sort(t_d_linklst *list);
void				quick_sort(t_node *head, t_node *tail);
t_d_linklst			*ft_list_dup(t_d_linklst *list);
T					find_median(t_d_linklst *list);
void				r_w_sort(t_d_linklst *a, t_d_linklst *b, char **str);
size_t				count_small(t_d_linklst *list, long int median);
size_t				count_large(t_d_linklst *list, long int median);
void				move_to_a(t_d_linklst *list_a, t_d_linklst *list_b,
					char **str);
void				optimize(char *str);
int					if_biggest(t_d_linklst *l, long int val);
void				revers(char **str, int tmp);
void				revers1(char **str, int tmp);
t_d_linklst			*ft_list_dup_to(t_d_linklst *list);
int					is_sort_b(t_d_linklst *b);
void				bum(t_d_linklst *a, t_d_linklst *b, char **str);
void				optimize(char *str);
void				push_a_and_b(char **str, int tmp);
void				do_it_shit(t_d_linklst *a, t_d_linklst *b, char **str);
void				rra_mod(t_d_linklst *list);
void				ra_mod(t_d_linklst *list);
void				sa_mod(t_d_linklst *list_a);
void				sort_three_dow_b(t_d_linklst *b, char **str);
void				sort_four(t_d_linklst *a, t_d_linklst *b, t_d_linklst *c,
					char **str);
int					min_s(t_d_linklst *l, char **str);
void				f_4(t_d_linklst *a, t_d_linklst *b, char **str);
char				*tell_me(t_d_linklst *l, char *str);
void				mod(t_d_linklst *new, int i, int f);
size_t				analize(size_t *arr, size_t des);
void				initial(t_d_linklst *a, t_d_linklst *b);
#endif
