/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiikang <jiikang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 10:16:05 by jiikang           #+#    #+#             */
/*   Updated: 2022/01/16 21:23:05 by yeblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char		g_board[4][4] = {0, };
char		g_input[16];
void	check_num(void);
void	backtracking(int index, int num);
void	make_zero(void);
void	print_board(void);
extern int	g_is_solve;

int	valid_input(char *av)
{
	int	i;
	int	count;
	int	num;

	i = 0;
	count = 0;
	num = 0;
	while (av[i] != '\0')
	{
		if (i % 2 == 0 && av[i] >= '1' && av[i] <= '4')
			count++;
		else if ((i % 2 == 1 && av[i] != ' ') || (i % 2 == 0 && av[i] == ' '))
			return (0);
		i++;
	}
	if (count != 16 || (av[i - 1] && !(av[i - 1] >= '1' && av[i - 1] <= '4')))
		return (0);
	return (1);
}

int	isit_match(void)
{
	int	row;
	int	col;
	int	couple;

	row = 8;
	col = 0;
	couple = 4;
	while (col < 4)
	{
		if (g_input[col] - '0' + g_input[col + couple] - '0' > 5)
			return (0);
		else if (g_input[col] - '0' + g_input[col + couple] - '0' < 3)
			return (0);
		col++;
	}
	while (row < 12)
	{
		if (g_input[row] - '0' + g_input[row + couple] - '0' > 5)
			return (0);
		else if (g_input[row] - '0' + g_input[row + couple] - '0' < 3)
			return (0);
		row++;
	}
	return (1);
}

void	make_input(char *av)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (av[i] != '\0')
	{
		if (av[i] != ' ')
		{
			g_input[j] = av[i];
			j++;
		}
		i++;
	}
}

void	make_board(void)
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
			g_board[i][j] = 48;
			j++;
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac != 2 || !valid_input(av[1]))
	{
		write(1, "Error", 6);
		return (0);
	}
	make_input(av[1]);
	if (!isit_match())
	{
		write(1, "Error", 6);
		return (0);
	}
	make_board();
	check_num();
	make_zero();
	backtracking(0, 1);
	if (!g_is_solve)
		write(1, "Error", 6);
	else
		print_board();
	return (0);
}
