/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 19:01:56 by doykim            #+#    #+#             */
/*   Updated: 2022/01/19 21:05:43 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	exception_handle(char *base, int len)
{
	int	i;
	int	j;

	i = 0;
	if (len <= 1)
		return (1);
	while (i < len)
	{
		if (base[i] == '+' || base[i] == '-' || base[i] == ' '
			|| base[i] == '\t' || base[i] == '\n' || base[i] == '\v'
			|| base[i] == '\f' || base[i] == '\r')
			return (1);
		j = i + 1;
		while (base[j])
			if (base[i] == base[j++])
				return (1);
		i++;
	}
	if (i == 1 && !i)
		return (1);
	return (0);
}

void	ft_change_print(long nb, char *base, int len)
{
	if (nb >= len)
		ft_change_print(nb / len, base, len);
	write(1, &base[nb % len], 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		len;
	int		flag;
	long	long_nbr;

	long_nbr = (long)nbr;
	len = 0;
	flag = 0;
	while (base[len])
		len++;
	flag = exception_handle(base, len);
	if (flag)
		return ;
	if (long_nbr < 0)
	{
		write(1, "-", 1);
		long_nbr *= -1;
	}
	ft_change_print(long_nbr, base, len);
}
