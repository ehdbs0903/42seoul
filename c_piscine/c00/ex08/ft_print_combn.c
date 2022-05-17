/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 20:41:47 by doykim            #+#    #+#             */
/*   Updated: 2022/01/08 17:03:16 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	recursiv_while(int i, int n, char arr[])
{
	int	k;

	k = 0;
	while (arr[i] <= '9')
	{
		arr[i + 1] = arr[i] + 1;
		if (i != n - 1)
			recursiv_while(i + 1, n, arr);
		else
		{
			if (arr[0] == '9' - n + 1)
				break ;
			while (k < n)
			{
				write(1, &arr[k], 1);
				k++;
			}
			k = 0;
			write(1, ", ", 2);
		}
		arr[i]++;
	}
}

void	ft_print_combn(int n)
{
	char	arr[10];
	char	c;
	int		i;

	i = 0;
	while (i < n)
	{
		arr[i] = i + 48;
		i++;
	}
	i = 0;
	recursiv_while(i, n, arr);
	i = 0;
	while (i < n)
	{
		c = '9' - n + i + 1;
		write(1, &c, 1);
		i++;
	}
}
