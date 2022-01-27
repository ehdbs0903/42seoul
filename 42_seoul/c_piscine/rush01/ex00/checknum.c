/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checknum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiikang <jiikang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 19:52:22 by doykim            #+#    #+#             */
/*   Updated: 2022/01/16 16:08:01 by jiikang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
void		check1(int i);
void		check2(int i);
void		check3(int i);
void		check4(int i);
extern char	g_board[4][4];
extern char	g_input[16];

void	check_num(void)
{
	int	i;

	i = 0;
	while (g_input[i] != '\0')
	{
		if (g_input[i] == '1')
			check1(i);
		else if (g_input[i] == '2')
			check2(i);
		else if (g_input[i] == '3')
			check3(i);
		else if (g_input[i] == '4')
			check4(i);
		i++;
	}
}

void	check1(int i)
{
	if (i < 4)
		g_board[0][i] = '4';
	else if (i >= 4 && i < 8)
		g_board[3][i - 4] = '4';
	else if (i >= 8 && i < 12)
		g_board[i - 8][0] = '4';
	else if (i >= 12 && i < 16)
		g_board[i - 12][3] = '4';
}

void	check2(int i)
{
	if (i < 4 && g_input[i + 4] == '1')
		g_board[0][i] = '3';
	else if (i >= 4 && i < 8 && g_input[i - 4] == '1')
		g_board[3][i - 4] = '3';
	else if (i >= 8 && i < 12 && g_input[i + 4] == '1')
		g_board[i - 8][0] = '3';
	else if (i >= 12 && i < 16 && g_input[i - 4] == '1')
		g_board[i - 12][3] = '3';
}

void	check3(int i)
{
	if (i < 4 && g_input[i + 4] == '2')
		g_board[2][i] = '4';
	else if (i >= 4 && i < 8 && g_input[i - 4] == '2')
		g_board[1][i - 4] = '4';
	else if (i >= 8 && i < 12 && g_input[i + 4] == '2')
		g_board[i - 8][2] = '4';
	else if (i >= 12 && i < 16 && g_input[i - 4] == '2')
		g_board[i - 12][1] = '4';
}

void	check4(int i)
{
	if (i < 4)
	{
		g_board[0][i] = '1';
		g_board[1][i] = '2';
		g_board[2][i] = '3';
	}
	else if (i >= 4 && i < 8)
	{
		g_board[3][i - 4] = '1';
		g_board[2][i - 4] = '2';
		g_board[1][i - 4] = '3';
	}
	else if (i >= 8 && i < 12)
	{
		g_board[i - 8][0] = '1';
		g_board[i - 8][1] = '2';
		g_board[i - 8][2] = '3';
	}
	else if (i >= 12 && i < 16)
	{
		g_board[i - 12][3] = '1';
		g_board[i - 12][2] = '2';
		g_board[i - 12][1] = '3';
	}
}
