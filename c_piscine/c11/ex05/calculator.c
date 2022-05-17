/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 21:11:24 by doykim            #+#    #+#             */
/*   Updated: 2022/01/25 21:41:45 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	add(int a, int b);
void	sub(int a, int b);
void	mul(int a, int b);
void	div(int a, int b);
void	mod(int a, int b);

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

void	calculator(char **argv)
{
	int	a;
	int	b;

	a = ft_atoi(argv[1]);
	b = ft_atoi(argv[3]);
	if (argv[2][0] == '+')
		add(a, b);
	if (argv[2][0] == '-')
		sub(a, b);
	if (argv[2][0] == '*')
		mul(a, b);
	if (argv[2][0] == '/')
		div(a, b);
	if (argv[2][0] == '%')
		mod(a, b);
}
