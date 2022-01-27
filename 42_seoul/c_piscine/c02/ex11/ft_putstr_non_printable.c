/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 21:35:15 by doykim            #+#    #+#             */
/*   Updated: 2022/01/15 08:40:37 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	char_to_hex(char c)
{
	if (c < 10)
		c += '0';
	else if (c == 10)
		c = 'a';
	else if (c == 11)
		c = 'b';
	else if (c == 12)
		c = 'c';
	else if (c == 13)
		c = 'd';
	else if (c == 14)
		c = 'e';
	else if (c == 15)
		c = 'f';
	return (c);
}

char	*nonprint_to_hex(char *temp, char c)
{
	temp[0] = (unsigned char)c / 16;
	temp[1] = (unsigned char)c % 16;
	temp[0] = char_to_hex(temp[0]);
	temp[1] = char_to_hex(temp[1]);
	return (temp);
}

void	ft_putstr_non_printable(char *str)
{
	int		i;
	int		len;
	char	temp[2];

	i = 0;
	len = 0;
	while (str[len] != '\0')
		len++;
	while (i < len)
	{
		if (!(str[i] >= 32 && str[i] <= 126))
		{
			write(1, "\\", 1);
			write(1, nonprint_to_hex(temp, str[i]), 2);
		}
		else
			write(1, &str[i], 1);
		i++;
	}
}
