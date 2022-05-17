/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 21:51:55 by doykim            #+#    #+#             */
/*   Updated: 2022/01/19 11:36:29 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_find_next_prime(int nb)
{
	int	i;
	int	flag;

	flag = 0;
	if (nb <= 2)
		return (2);
	while (1)
	{
		i = 2;
		while (i * i <= nb && i < 46341)
		{
			if (nb % i == 0)
			{
				flag = 0;
				break ;
			}
			else
				flag = 1;
			i++;
		}
		if (flag)
			return (nb);
		nb++;
	}
}
