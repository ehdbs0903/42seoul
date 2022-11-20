/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 12:57:43 by doykim            #+#    #+#             */
/*   Updated: 2022/11/20 13:29:12 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

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
	if (!(check_sorted(lists->a)))
		sort_list(lists);
	free_lists(lists);
	return (0);
}
