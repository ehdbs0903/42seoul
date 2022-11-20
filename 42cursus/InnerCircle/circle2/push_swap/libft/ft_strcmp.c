/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 02:47:39 by doykim            #+#    #+#             */
/*   Updated: 2022/11/20 03:14:17 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*ss1;
	unsigned char	*ss2;
	int				idx;

	ss1 = (unsigned char *)s1;
	ss2 = (unsigned char *)s2;
	idx = 0;
	while ((ss1[idx] || ss2[idx]))
	{
		if (ss1[idx] != ss2[idx])
			return (ss1[idx] - ss2[idx]);
		idx++;
	}
	return (0);
}
