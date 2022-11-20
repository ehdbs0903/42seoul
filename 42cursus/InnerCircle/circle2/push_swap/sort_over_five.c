/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_over_five.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 21:31:48 by doykim            #+#    #+#             */
/*   Updated: 2022/11/20 13:30:06 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	get_chunk(t_dllist *list)
{
	int	size;
	int	chunk;

	size = list->size;
	chunk = 0.000000053 * size * size + 0.03 * size + 14.5;
	return (chunk);
}

void	a_to_b(t_lists *lists, int chunk)
{
	int	i;

	i = 0;
	while (lists->a->size)
	{
		if (lists->a->top->index <= i)
		{
			pb(lists, 0);
			i++;
		}
		else if (lists->a->top->index > i && lists->a->top->index <= i + chunk)
		{
			pb(lists, 0);
			rb(lists, 0);
			i++;
		}
		else
		{
			if (i < lists->a->size / 2)
				rra(lists, 0);
			else
				ra(lists, 0);
		}
	}
}

void	b_to_a(t_lists *lists)
{
	while (lists->b->size)
	{
		get_top_index(lists);
		pa(lists, 0);
	}
}

void	get_top_index(t_lists *lists)
{
	int		i;
	int		max_index;
	t_node	*temp;

	i = 0;
	max_index = lists->b->size - 1;
	temp = lists->b->top;
	if (temp->index == max_index)
		return ;
	while (temp->index != max_index)
	{
		temp = temp->next;
		i++;
	}
	if (i < lists->b->size / 2)
		while (lists->b->top != temp)
			rb(lists, 0);
	else
		while (lists->b->top != temp)
			rrb(lists, 0);
}
