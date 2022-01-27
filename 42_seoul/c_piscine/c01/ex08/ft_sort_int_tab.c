/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 11:27:12 by doykim            #+#    #+#             */
/*   Updated: 2022/01/09 12:25:02 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_sort_int_tab(int *tab, int size)
{
	int	idx;
	int	i;
	int	temp;

	i = 0;
	idx = 0;
	while (i++ < size)
	{
		while (idx < size - 1)
		{
			if (tab[idx] > tab[idx + 1])
			{
				temp = tab[idx];
				tab[idx] = tab[idx + 1];
				tab[idx + 1] = temp;
			}
			idx++;
		}
		idx = 0;
	}
}
