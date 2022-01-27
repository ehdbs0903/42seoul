/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 21:14:41 by doykim            #+#    #+#             */
/*   Updated: 2022/01/24 17:22:06 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	cal_minus(int minus_cnt, int *ret)
{
	if (minus_cnt % 2 != 0)
		*ret *= -1;
}

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

int	ft_nbr(char *str, char *base)
{
	int	i;
	int	ret;
	int	cnt;
	int	len;

	len = 0;
	while (base[len])
		len++;
	ret = 0;
	i = 0;
	cnt = 0;
	while (base[i])
	{
		if (*str == base[i])
		{
			ret = ret * len + i;
			i = -1;
			str++;
			cnt++;
		}
		i++;
	}
	return (ret);
}

int	ft_atoi(char *str, char *base, int minus_cnt, int ret)
{
	int	flag;

	flag = 1;
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
		else
		{
			ret = ft_nbr(str, base);
			break ;
		}
		str++;
	}
	cal_minus(minus_cnt, &ret);
	return (ret);
}

int	ft_atoi_base(char *str, char *base)
{
	long	n;
	int		flag;
	int		idx;
	int		len;

	idx = 0;
	len = 0;
	while (base[len])
		len++;
	flag = exception_handle(base, len);
	if (flag)
		return (0);
	n = ft_atoi(str, base, 0, 0);
	return (n);
}
