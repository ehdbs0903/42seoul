/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 08:21:10 by doykim            #+#    #+#             */
/*   Updated: 2022/01/20 12:40:40 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	write(1, s, len);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	idx;
	int	len;

	idx = 0;
	len = 0;
	while (s1[len] != '\0')
		len++;
	while (idx < len)
	{
		if (s1[idx] < s2[idx])
			return (-1);
		else if (s1[idx] > s2[idx])
			return (1);
		idx++;
	}
	if (s1[idx])
		return (1);
	if (s2[idx])
		return (-1);
	return (0);
}

int	main(int argc, char **argv)
{
	int		i;
	int		j;
	char	*temp;

	j = 0;
	while (++j < argc)
	{
		i = 1;
		while (i < argc - j)
		{
			if (ft_strcmp(argv[i], argv[i + 1]) == 1)
			{
				temp = argv[i];
				argv[i] = argv[i + 1];
				argv[i + 1] = temp;
			}
			i++;
		}
	}
	i = 1;
	while (i < argc)
	{
		ft_putstr(argv[i++]);
		write(1, "\n", 1);
	}
}
