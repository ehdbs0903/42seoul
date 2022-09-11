/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 18:54:48 by doykim            #+#    #+#             */
/*   Updated: 2022/05/10 16:09:16 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		minus;
	long	result;

	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	minus = 0;
	if (*str == '-')
	{
		minus = 1;
		str++;
	}
	else if (*str == '+')
		str++;
	result = 0;
	while (*str >= '0' && *str <= '9')
		result = result * 10 + *str++ - '0';
	if (minus)
		result *= -1;
	if (result > 2147483647)
		return (-1);
	else if (result < -2147483648)
		return (0);
	return ((int)result);
}
