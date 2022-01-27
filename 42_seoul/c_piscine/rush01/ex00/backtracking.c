/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiikang <jiikang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 10:14:28 by doykim            #+#    #+#             */
/*   Updated: 2022/01/16 21:24:20 by yeblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

extern int	ispossible(int row, int col, int num);
extern int	check_rowandcol(void);
extern char	g_board[4][4];
extern char	g_input[16];
int			g_zero_arr[16][2] = {0, };
int			g_is_solve = 0;
int			g_cnt = 0;

int	ispromising(int row, int col, int num)
{
	int	i;

	i = 0;
	while (i < 4)
		if (g_board[row][i++] == num + '0')
			return (0);
	i = 0;
	while (i < 4)
		if (g_board[i++][col] == num + '0')
			return (0);
	return (1);
}

void	print_board(void)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			write(1, &g_board[i][j], 1);
			write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

void	make_zero(void)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (g_board[i][j] == '0')
			{
				g_zero_arr[g_cnt][0] = i;
				g_zero_arr[g_cnt][1] = j;
				g_cnt++;
			}
			j++;
		}
		i++;
	}
}

void	backtracking(int index, int num)
{
	int	i;

	i = num - 1;
	while (++i <= 4)
	{
		if (ispromising(g_zero_arr[index][0], g_zero_arr[index][1], i)
			&& ispossible(g_zero_arr[index][0], g_zero_arr[index][1], i))
		{		
			g_board[g_zero_arr[index][0]][g_zero_arr[index][1]] = i + '0';
			if (index + 1 == g_cnt)
			{
				if (!check_rowandcol())
				{
					g_board[g_zero_arr[index][0]][g_zero_arr[index][1]] = '0';
					return ;
				}
				g_is_solve = 1;
				return ;
			}
			backtracking(index + 1, 1);
			if (g_is_solve)
				return ;
			g_board[g_zero_arr[index][0]][g_zero_arr[index][1]] = '0';
		}
	}
}
