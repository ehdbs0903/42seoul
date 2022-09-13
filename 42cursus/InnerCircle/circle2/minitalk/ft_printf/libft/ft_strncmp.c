/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 17:17:02 by doykim            #+#    #+#             */
/*   Updated: 2022/03/22 16:58:00 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			idx;
	unsigned char	*ss1;
	unsigned char	*ss2;

	ss1 = (unsigned char *)s1;
	ss2 = (unsigned char *)s2;
	idx = 0;
	if (n == 0)
		return (0);
	while ((ss1[idx] || ss2[idx]) && idx < n)
	{
		if (ss1[idx] != ss2[idx])
			return (ss1[idx] - ss2[idx]);
		idx++;
	}
	return (0);
}
