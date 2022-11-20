/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 21:34:50 by doykim            #+#    #+#             */
/*   Updated: 2022/11/20 13:31:24 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	free_list(t_dllist *list)
{
	int		size;
	t_node	*temp;

	size = list->size;
	while (size)
	{
		temp = list->top->next;
		free(list->top);
		list->top = NULL;
		list->top = temp;
		size--;
	}
	free(list);
	list = NULL;
}

void	free_lists(t_lists *lists)
{
	free_list(lists->a);
	free_list(lists->b);
	free(lists);
	lists = NULL;
}
