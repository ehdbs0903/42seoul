/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungchoi <jungchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 14:33:09 by jungchoi          #+#    #+#             */
/*   Updated: 2022/03/24 13:02:01 by jungchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len_check(long long n)
{
	int	len;

	len = 0;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static void	putarr(char *ret, int len, long long ln)
{
	*(ret + len) = '\0';
	while (len--)
	{
		*(ret + len) = ln % 10 + '0';
		ln /= 10;
	}
}

char	*ft_itoa(int n)
{
	char		*ret;
	int			len;
	int			sign;
	long long	ln;

	ln = (long long)n;
	if (ln == 0)
		return (ft_strdup("0"));
	sign = 1;
	if (ln < 0)
	{
		ln = -ln;
		sign = -1;
	}
	len = len_check(ln);
	if (sign == -1)
		len++;
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (0);
	putarr(ret, len, ln);
	if (sign == -1)
		*ret = '-';
	return (ret);
}
