/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 21:20:07 by doykim            #+#    #+#             */
/*   Updated: 2022/11/20 13:29:47 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	reverse_rotate(t_dllist *list)
{
	if (list->size < 2)
		return ;
	list->top = list->top->prev;
	list->bottom = list->bottom->prev;
}

void	rra(t_lists *lists, int flag)
{
	reverse_rotate(lists->a);
	if (!flag)
		write(1, "rra\n", 4);
}

void	rrb(t_lists *lists, int flag)
{
	reverse_rotate(lists->b);
	if (!flag)
		write(1, "rrb\n", 4);
}

void	rrr(t_lists *lists, int flag)
{
	reverse_rotate(lists->a);
	reverse_rotate(lists->b);
	if (!flag)
		write(1, "rrr\n", 4);
}
