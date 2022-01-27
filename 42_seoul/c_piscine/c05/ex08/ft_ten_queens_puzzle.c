/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 13:02:13 by doykim            #+#    #+#             */
/*   Updated: 2022/01/19 11:36:47 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	g_arr[10];
int		g_cnt = 0;

void	print(void)
{
	write(1, g_arr, 10);
	write(1, "\n", 1);
}

int	check_valid(int i, int idx)
{
	int	j;

	j = 0;
	while (j < idx)
	{
		if (g_arr[j] == i + '0')
			return (0);
		if (i + '0' - g_arr[j] == idx - j)
			return (0);
		if (i + '0' - g_arr[j] == - (idx - j))
			return (0);
		j++;
	}
	return (1);
}

void	queens(int idx)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		if (check_valid(i, idx))
		{	
			g_arr[idx] = i + '0';
			if (idx < 9)
			{
				queens(idx + 1);
				g_arr[idx] = -1;
			}
			else
			{
				print();
				g_cnt++;
			}
		}
		i++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	i;

	i = 0;
	while (i < 10)
		g_arr[i++] = -1;
	queens(0);
	return (g_cnt);
}
