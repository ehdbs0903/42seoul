/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 21:17:56 by doykim            #+#    #+#             */
/*   Updated: 2022/11/20 11:43:50 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	rotate(t_dllist *list)
{
	if (list->size < 2)
		return ;
	list->top = list->top->next;
	list->bottom = list->bottom->next;
}

void	ra(t_lists *lists, int flag)
{
	rotate(lists->a);
	if (!flag)
		write(1, "ra\n", 3);
}

void	rb(t_lists *lists, int flag)
{
	rotate(lists->b);
	if (!flag)
		write(1, "rb\n", 3);
}

void	rr(t_lists *lists, int flag)
{
	rotate(lists->a);
	rotate(lists->b);
	if (!flag)
		write(1, "rr\n", 3);
}
