/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 21:18:55 by doykim            #+#    #+#             */
/*   Updated: 2022/11/20 13:30:17 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	push(t_dllist *list, t_node *node)
{
	if (list->size == 0)
	{
		node->prev = node;
		node->next = node;
		list->top = node;
		list->bottom = node;
	}
	else
	{
		node->next = list->top;
		node->prev = list->bottom;
		list->top->prev = node;
		list->bottom->next = node;
		list->top = node;
	}
	list->size += 1;
}

t_node	*pop(t_dllist *list)
{
	t_node	*temp;

	if (list->size == 0)
		return (NULL);
	temp = list->top;
	if (list->size == 1)
	{
		list->top = NULL;
		list->bottom = NULL;
	}
	else
	{
		list->top = list->top->next;
		list->top->prev = list->bottom;
		list->bottom->next = list->top;
	}
	list->size -= 1;
	return (temp);
}

void	pa(t_lists *lists, int flag)
{
	t_node	*node;

	node = pop(lists->b);
	if (!node)
		return ;
	push(lists->a, node);
	if (!flag)
		write(1, "pa\n", 3);
}

void	pb(t_lists *lists, int flag)
{
	t_node	*node;

	node = pop(lists->a);
	if (!node)
		return ;
	push(lists->b, node);
	if (!flag)
		write(1, "pb\n", 3);
}
