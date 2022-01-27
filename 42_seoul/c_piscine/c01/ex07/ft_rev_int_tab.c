/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 10:44:16 by doykim            #+#    #+#             */
/*   Updated: 2022/01/09 11:26:30 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	mid;
	int	idx;
	int	temp;

	idx = 0;
	mid = size / 2;
	while (idx < mid)
	{
		temp = tab[idx];
		tab[idx] = tab[size - idx - 1];
		tab[size - idx - 1] = temp;
		idx++;
	}
}
