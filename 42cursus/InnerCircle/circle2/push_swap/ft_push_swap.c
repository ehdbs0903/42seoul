/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 12:57:43 by doykim            #+#    #+#             */
/*   Updated: 2022/09/27 15:55:34 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
#include <stdio.h>

int	check_error(int ac, char **av, t_list **stack)
{
	int		i;
	int
	t_list	*temp;

	if (ac <= 1)
		return (0);
	i = 1;
	while (av[i])
	{
		
		if (!ft_isdigit((int)av[i]))
		{
			printf("%d\n", (int)av[i]);
			//if ft_isdigit == 0, stack clear
			return (0);
		}
		temp = ft_lstnew((int)av[i]);
		//if temp == 0, ft_lstnew return 0
		ft_lstadd_back(stack, temp);

	}
	return (1);
}

int	main(int ac, char **av)
{
	static t_list	**stack;
	t_list	*lst;
	
	if (!check_error(ac, av, stack))
	{
		printf("Error");
		return (0);
	}
	lst = stack[0];
	while (lst->next)
	{
		printf("%d ", lst->content);
		lst = lst->next;
	}
	printf("\n");
	return (0);
}
