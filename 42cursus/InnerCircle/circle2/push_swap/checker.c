/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 01:46:18 by doykim            #+#    #+#             */
/*   Updated: 2022/11/20 13:31:11 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void	operate(t_lists *lists, const char *op)
{
	if (ft_strcmp(op, "pa\n") == 0)
		pa(lists, 1);
	else if (ft_strcmp(op, "pb\n") == 0)
		pb(lists, 1);
	else if (ft_strcmp(op, "sa\n") == 0)
		sa(lists, 1);
	else if (ft_strcmp(op, "sb\n") == 0)
		sb(lists, 1);
	else if (ft_strcmp(op, "ss\n") == 0)
		ss(lists, 1);
	else if (ft_strcmp(op, "ra\n") == 0)
		ra(lists, 1);
	else if (ft_strcmp(op, "rb\n") == 0)
		rb(lists, 1);
	else if (ft_strcmp(op, "rr\n") == 0)
		rr(lists, 1);
	else if (ft_strcmp(op, "rra\n") == 0)
		rra(lists, 1);
	else if (ft_strcmp(op, "rrb\n") == 0)
		rrb(lists, 1);
	else if (ft_strcmp(op, "rrr\n") == 0)
		rrr(lists, 1);
	else
		print_error();
}

static void	checker(t_lists *lists)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		operate(lists, (const char *)line);
		free(line);
		line = get_next_line(0);
	}
	free(line);
	if (check_sorted(lists->a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int argc, char *argv[])
{
	t_lists	*lists;

	if (argc < 2)
		return (0);
	lists = (t_lists *)malloc(sizeof(t_lists));
	if (!lists)
		return (0);
	lists->a = init_list();
	lists->b = init_list();
	check_input(argv, lists);
	checker(lists);
	free_lists(lists);
	return (0);
}
