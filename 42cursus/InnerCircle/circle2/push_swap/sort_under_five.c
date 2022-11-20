/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_under_five.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 21:32:29 by doykim            #+#    #+#             */
/*   Updated: 2022/11/20 13:32:03 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	sort_two_node(t_lists *lists)
{
	if (lists->a->top->index > lists->a->top->next->index)
		sa(lists, 0);
}

void	sort_three_node(t_lists *lists)
{
	int	first;
	int	second;
	int	third;

	first = lists->a->top->index;
	second = lists->a->top->next->index;
	third = lists->a->top->next->next->index;
	sort_three_node_index(lists, first, second, third);
}

void	sort_three_node_index(t_lists *lists, int first, int second, int third)
{
	if (first < second)
	{
		if (second > third && first < third)
		{
			rra(lists, 0);
			sa(lists, 0);
		}
		else if (second > third && first > third)
			rra(lists, 0);
	}
	else
	{
		if (second < third && first < third)
			sa(lists, 0);
		else if (second < third && first > third)
			ra(lists, 0);
		else if (second > third)
		{
			ra(lists, 0);
			sa(lists, 0);
		}
	}
}

void	sort_four_or_five_node(t_lists *lists)
{
	while (lists->a->size > 3)
	{
		if (lists->a->top->index < 2)
			pb(lists, 0);
		else
			ra(lists, 0);
	}
	sort_three_node(lists);
	while (lists->b->size)
		pa(lists, 0);
	if (lists->a->top->index != 0)
		sa(lists, 0);
}
