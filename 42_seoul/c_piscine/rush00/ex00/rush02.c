/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 09:32:01 by doykim            #+#    #+#             */
/*   Updated: 2022/01/27 11:05:18 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	ft_f_line(int x)
{
	int	count;

	count = 0;
	if (x == 1)
		ft_putchar('A');
	else
	{
		while (count < x)
		{
			if (count == 0 || count == x - 1)
				ft_putchar('A');
			else
				ft_putchar('B');
			count ++;
		}
	}
}

void	ft_m(int x)
{
	int	count;

	count = 0;
	if (x == 1)
		ft_putchar('B');
	else
	{
		while (count < x)
		{
			if (count == 0 || count == x - 1)
				ft_putchar('B');
			else
				ft_putchar(' ');
			count ++;
		}
	}
}

void	ft_l_line(int x)
{
	int	count;

	count = 0;
	if (x == 1)
		ft_putchar('C');
	else
	{
		while (count < x)
		{
			if (count == 0 || count == x - 1)
				ft_putchar('C');
			else
				ft_putchar('B');
			count ++;
		}
	}
}

void	rush02(int x, int y)
{
	int	count;

	count = 0;
	if (y == 1)
		ft_f_line(x);
	else
	{
		while (count < y)
		{
			if (count == 0)
			{
				ft_f_line(x);
				ft_putchar('\n');
			}
			else if (count == y - 1)
				ft_l_line(x);
			else
			{
				ft_m(x);
				ft_putchar('\n');
			}
			count ++;
		}
	}
}
