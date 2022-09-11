/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 17:09:47 by doykim            #+#    #+#             */
/*   Updated: 2022/03/15 16:12:38 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*reverse_s;

	reverse_s = s + ft_strlen(s);
	while (reverse_s >= s)
	{
		if (*reverse_s == c)
			return ((char *)reverse_s);
		reverse_s--;
	}
	return (0);
}
