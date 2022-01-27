/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 15:21:11 by doykim            #+#    #+#             */
/*   Updated: 2022/01/18 17:10:42 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	cal_ret(char *str, int ret)
{
	while (*str <= '9' && *str >= '0')
		ret = ret * 10 + *str++ - '0';
	return (ret);
}

int	ft_atoi2(char *str, int minus_cnt, int ret, int flag)
{
	while (*str)
	{
		if (*str == '-' || *str == '+')
		{
			if (*str == '-')
				minus_cnt++;
			flag = 0;
		}
		else if (*str == ' ' || (*str >= 9 && *str <= 13))
		{
			if (!flag)
				break ;
		}
		else if (!(*str <= '9' && *str >= '0'))
			break ;
		else
		{
			ret = cal_ret(str, ret);
			break ;
		}
		str++;
	}
	if (minus_cnt % 2 != 0)
		ret *= -1;
	return (ret);
}

int	ft_atoi(char *str)
{
	return (ft_atoi2(str, 0, 0, 1));
}
