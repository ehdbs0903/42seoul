/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 16:18:37 by doykim            #+#    #+#             */
/*   Updated: 2022/01/16 13:07:33 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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
