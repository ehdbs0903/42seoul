/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 18:56:59 by doykim            #+#    #+#             */
/*   Updated: 2022/01/27 15:53:13 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int(*f)(int, int))
{
	int	i;
	int	flag;

	flag = 0;
	i = -1;
	while (++i < length - 1)
	{
		if (f(tab[i], tab[i + 1]))
		{
			flag = f(tab[i], tab[i + 1]);
			break ;
		}
	}
	i = 0;
	while (i < length - 1)
	{
		if (flag > 0)
			if (f(tab[i], tab[i + 1]) < 0)
				return (0);
		if (flag < 0)
			if (f(tab[i], tab[i + 1]) > 0)
				return (0);
		i++;
	}
	return (1);
}
