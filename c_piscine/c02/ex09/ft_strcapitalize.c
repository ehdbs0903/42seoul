/* ************************************************************************** */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 17:22:17 by doykim            #+#    #+#             */
/*   Updated: 2022/01/09 19:20:19 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_capital2(char *str, int idx, int flag)
{
	while (str[idx] != '\0')
	{
		if (flag && str[idx] >= 'a' && str[idx] <= 'z')
		{
			str[idx] -= 32;
			flag = 0;
		}
		else if (str[idx] >= '0' && str[idx] <= '9')
			flag = 0;
		else if (!(str[idx] >= 'A' && str[idx] <= 'Z'))
		{
			if (!(str[idx] >= 'a' && str[idx] <= 'z'))
				flag = 1;
		}
		else if (str[idx] >= 'A' && str[idx] <= 'Z')
		{
			if (!flag)
				str[idx] += 32;
			else
				flag = 0;
		}
		idx++;
	}
}

char	*ft_strcapitalize(char *str)
{
	ft_capital2(str, 0, 1);
	return (str);
}
