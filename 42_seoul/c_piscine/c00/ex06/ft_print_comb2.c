/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 19:09:29 by doykim            #+#    #+#             */
/*   Updated: 2022/01/08 20:48:08 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_sub(char i, char j)
{
	char	k;
	char	l;

	k = i - 1;
	while (k++ < '9')
	{
		if (i == k)
			l = j;
		else
			l = '0' - 1;
		while (l++ < '9')
		{
			if (i == '9' && j == '8')
			{
				break ;
			}
			write(1, &i, 1);
			write(1, &j, 1);
			write(1, " ", 1);
			write(1, &k, 1);
			write(1, &l, 1);
			write(1, ", ", 2);
		}
	}
}

void	ft_print_comb2(void)
{
	char	i;
	char	j;

	i = '0';
	while (i <= '9')
	{
		j = '0';
		while (j <= '9')
		{
			print_sub(i, j);
			j++;
		}
		i++;
	}
	write(1, "98 99", 5);
}
