/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 21:12:48 by doykim            #+#    #+#             */
/*   Updated: 2022/01/25 09:20:56 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static char	*g_arr;

int	ft_atoi_base(char *str, char *base);
int	exception_handle(char *base, int len);

void	ft_change(long nb, char *base, int len, int size)
{
	if (nb >= len)
		ft_change(nb / len, base, len, size - 1);
	g_arr[size] = base[nb % len];
}

void	ft_putnbr_base(int nbr, char *base, int size)
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
		g_arr[0] = '-';
		long_nbr *= -1;
		ft_change(long_nbr, base, len, size);
		g_arr[size + 1] = '\0';
	}
	else
	{
		ft_change(long_nbr, base, len, size - 1);
		g_arr[size] = '\0';
	}
}

int	cnt_size(long i, int base_to_len)
{
	int	size;

	size = 0;
	if (i == 0)
		return (1);
	if (i < 0)
		i *= -1;
	while (i > 0)
	{
		i /= base_to_len;
		size++;
	}
	return (size);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		n;
	long	i;
	int		base_to_len;
	int		base_from_len;
	int		size;

	size = 0;
	base_to_len = 0;
	base_from_len = 0;
	n = ft_atoi_base(nbr, base_from);
	i = 0;
	while (base_to[i++])
		base_to_len++;
	i = 0;
	while (base_from[i++])
		base_from_len++;
	if (exception_handle(base_from, base_from_len)
		|| exception_handle(base_to, base_to_len))
		return (0);
	size = cnt_size(n, base_to_len);
	g_arr = (char *)malloc(sizeof (char) * (size + 2));
	ft_putnbr_base(n, base_to, size);
	return (g_arr);
}
