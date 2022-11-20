/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 21:14:29 by doykim            #+#    #+#             */
/*   Updated: 2022/11/20 13:33:59 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	swap(t_dllist *list)
{
	int	temp;

	temp = list->top->num;
	list->top->num = list->top->next->num;
	list->top->next->num = temp;
	temp = list->top->index;
	list->top->index = list->top->next->index;
	list->top->next->index = temp;
}

void	sa(t_lists *lists, int flag)
{
	swap(lists->a);
	if (!flag)
		write(1, "sa\n", 3);
}

void	sb(t_lists *lists, int flag)
{
	swap(lists->b);
	if (!flag)
		write(1, "sb\n", 3);
}

void	ss(t_lists *lists, int flag)
{
	swap(lists->a);
	swap(lists->b);
	if (!flag)
		write(1, "ss\n", 3);
}
