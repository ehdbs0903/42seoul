/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 03:15:27 by doykim            #+#    #+#             */
/*   Updated: 2022/11/20 13:29:26 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

t_dllist	*init_list(void)
{
	t_dllist	*list;

	list = (t_dllist *)malloc(sizeof(t_dllist));
	if (!list)
		return (NULL);
	list->size = 0;
	list->top = NULL;
	list->bottom = NULL;
	return (list);
}

t_node	*init_node(int num)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->num = num;
	node->index = 0;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

void	print_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}
