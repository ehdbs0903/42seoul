/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 09:45:42 by doykim            #+#    #+#             */
/*   Updated: 2022/01/27 11:05:00 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	letter(int x, int y, int col, int row)
{
	if (row == 0 || row == y - 1)
	{
		if (col == 0 || col == x - 1)
			ft_putchar('o');
		else
			ft_putchar('-');
	}
	else
	{
		if (col == 0 || col == x - 1)
			ft_putchar('|');
		else
			ft_putchar(' ');
	}
}

void	rush00(int x, int y)
{
	int	col;
	int	row;

	row = 0;
	while (row <= y - 1)
	{
		col = 0;
		while (col <= x - 1)
		{
			letter(x, y, col, row);
			col++;
		}
		ft_putchar('\n');
		row++;
	}
}
