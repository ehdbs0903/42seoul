/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 14:51:32 by doykim            #+#    #+#             */
/*   Updated: 2022/05/10 16:10:13 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_len(int n)
{
	size_t	len;

	if (n == 0)
		return (1);
	len = 0;
	if (n < 0)
		len++;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static void	make_ret(char *ret, size_t len, size_t i, int n)
{
	while (len-- > i)
	{
		if (n < 0)
		{
			ret[len] = '0' + n % 10 * (-1);
			n = n / 10;
		}
		else
		{
			ret[len] = '0' + n % 10;
			n = n / 10;
		}
	}
}

char	*ft_itoa(int n)
{
	size_t	len;
	size_t	i;
	char	*ret;

	len = get_len(n);
	ret = (char *)malloc(len + 1);
	if (!ret)
		return (0);
	ret[len] = '\0';
	i = 0;
	if (n < 0)
	{
		ret[0] = '-';
		i = 1;
	}
	make_ret(ret, len, i, n);
	return (ret);
}
