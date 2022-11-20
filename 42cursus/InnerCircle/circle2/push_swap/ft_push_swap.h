/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 12:58:45 by doykim            #+#    #+#             */
/*   Updated: 2022/11/20 07:00:37 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include "libft/libft.h"
# include "get_next_line/get_next_line.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				num;
	int				index;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_dllist
{
	int				size;
	struct s_node	*top;
	struct s_node	*bottom;
}	t_dllist;

typedef struct s_lists
{
	struct s_dllist	*a;
	struct s_dllist	*b;
}	t_lists;

t_dllist	*init_list(void);
t_node		*init_node(int num);
void		print_error(void);

void		swap(t_dllist *list);
void		sa(t_lists *lists, int flag);
void		sb(t_lists *lists, int flag);
void		ss(t_lists *lists, int flag);

void		push(t_dllist *list, t_node *node);
t_node		*pop(t_dllist *list);
void		pa(t_lists *lists, int flag);
void		pb(t_lists *lists, int flag);

void		rotate(t_dllist *list);
void		ra(t_lists *lists, int flag);
void		rb(t_lists *lists, int flag);
void		rr(t_lists *lists, int flag);

void		reverse_rotate(t_dllist *list);
void		rra(t_lists *lists, int flag);
void		rrb(t_lists *lists, int flag);
void		rrr(t_lists *lists, int flag);

void		free_list(t_dllist *list);
void		free_lists(t_lists *lists);

void		split_input(char *str, t_lists *lists);
void		check_input(char **argv, t_lists *lists);
void		check_valid_input_and_push(char *str, t_lists *lists);
int			check_duplicate_and_indexing(t_dllist *list, t_node *node);

long long	atoll(const char *str);
long long	check_num(const char *str, int i, int sign);

void		sort_list(t_lists *lists);
void		sort_under_five(t_lists *lists);
void		sort_over_five(t_lists *lists);
int			check_sorted(t_dllist *list);

void		sort_two_node(t_lists *lists);
void		sort_three_node(t_lists *lists);
void		sort_three_node_index(t_lists *lists, int first, \
		int second, int third);
void		sort_four_or_five_node(t_lists *lists);

int			get_chunk(t_dllist *list);
void		a_to_b(t_lists *lists, int chunk);
void		b_to_a(t_lists *lists);
void		get_top_index(t_lists *lists);

#endif
