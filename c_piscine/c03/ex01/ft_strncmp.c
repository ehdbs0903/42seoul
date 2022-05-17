/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 16:34:40 by doykim            #+#    #+#             */
/*   Updated: 2022/01/18 11:31:16 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	idx;
	
	idx = 0;
	if (n == 0)
		return (0);
	while ((s1[idx] || s2[idx]) && idx < n)
	{
		if (s1[idx] < s2[idx])
			return (-1);
		else if (s1[idx] > s2[idx])
			return (1);
		idx++;
	}
	return (0);
}
