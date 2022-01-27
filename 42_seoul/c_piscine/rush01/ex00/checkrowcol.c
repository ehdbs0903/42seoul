/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkrowcol.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiikang <jiikang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 11:14:40 by jiikang           #+#    #+#             */
/*   Updated: 2022/01/16 20:31:13 by yeblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

extern char	g_board[4][4];
extern char	g_input[16];

int	check_col_up(void)
{
	int	i;
	int	j;
	int	nowheight;
	int	cansee;

	i = 0;
	while (i < 4)
	{
		j = 0;
		nowheight = g_board[0][i] - '0';
		cansee = 1;
		while (j < 4)
		{
			if (nowheight < g_board[j][i] - '0')
			{
				nowheight = g_board[j][i] - '0';
				cansee++;
			}
			j++;
		}
		if (cansee != g_input[i] - '0')
			return (0);
		i++;
	}
	return (1);
}

int	check_col_down(void)
{
	int	i;
	int	j;
	int	nowheight;
	int	cansee;

	i = 0;
	while (i < 4)
	{
		j = 3;
		nowheight = g_board[3][i] - '0';
		cansee = 1;
		while (-1 < j)
		{
			if (nowheight < g_board[j][i] - '0')
			{
				nowheight = g_board[j][i] - '0';
				cansee++;
			}
			j--;
		}
		if (cansee != g_input[4 + i] - '0')
			return (0);
		i++;
	}
	return (1);
}

int	check_row_left(void)
{
	int	i;
	int	j;
	int	nowheight;
	int	cansee;

	j = 0;
	while (j < 4)
	{
		i = 0;
		nowheight = g_board[j][0] - '0';
		cansee = 1;
		while (i < 4)
		{
			if (nowheight < g_board[j][i] - '0')
			{
				nowheight = g_board[j][i] - '0';
				cansee++;
			}
			i++;
		}
		if (cansee != g_input[8 + j] - '0')
			return (0);
		j++;
	}
	return (1);
}

int	check_row_right(void)
{
	int	i;
	int	j;
	int	nowheight;
	int	cansee;

	j = 0;
	while (j < 4)
	{
		i = 3;
		nowheight = g_board[j][3] - '0';
		cansee = 1;
		while (-1 < i)
		{
			if (nowheight < g_board[j][i] - '0')
			{
				nowheight = g_board[j][i] - '0';
				cansee++;
			}
			i--;
		}
		if (cansee != g_input[12 + j] - '0')
			return (0);
		j++;
	}
	return (1);
}

int	check_rowandcol(void)
{
	int	C;
	int	R;

	C = check_col_up() && check_col_down();
	R = check_row_left() && check_row_right();
	return (C && R);
}
