/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 04:22:02 by sanghan           #+#    #+#             */
/*   Updated: 2022/05/19 19:56:29 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_overflow(long sign);

int	ft_atoi(const char *str)
{
	long	result;
	long	sign;

	sign = 1;
	result = 0;
	while ((*str != '\0') && (*str == ' ' || *str == '\t' \
				|| *str == '\n' || *str == '\v' \
				|| *str == '\f' || *str == '\r'))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		if (result > result * 10 + *str - '0')
			return (ft_overflow(sign));
		result = result * 10 + *str - '0';
		str++;
	}
	return (sign * result);
}

static int	ft_overflow(long sign)
{
	if (sign == 1)
		return (-1);
	return (0);
}
