/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 21:19:57 by doykim            #+#    #+#             */
/*   Updated: 2022/01/27 10:33:19 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb);

void	add(int a, int b)
{
	ft_putnbr(a + b);
	write(1, "\n", 1);
}

void	sub(int a, int b)
{
	ft_putnbr(a - b);
	write(1, "\n", 1);
}

void	mul(int a, int b)
{
	ft_putnbr(a * b);
	write(1, "\n", 1);
}

void	div(int a, int b)
{
	if (!b)
	{
		write(1, "Stop : division by zero\n", 24);
		return ;
	}
	ft_putnbr(a / b);
	write(1, "\n", 1);
}

void	mod(int a, int b)
{
	if (!b)
	{
		write(1, "Stop : modulo by zero\n", 22);
		return ;
	}
	ft_putnbr(a % b);
	write(1, "\n", 1);
}
