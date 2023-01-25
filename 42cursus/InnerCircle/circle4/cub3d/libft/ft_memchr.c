/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 04:20:20 by sanghan           #+#    #+#             */
/*   Updated: 2022/05/20 14:33:57 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*new_b;
	unsigned char	find;

	new_b = (unsigned char *)s;
	find = c;
	while (n--)
	{
		if (*new_b++ == find)
			return ((void *)(new_b - 1));
	}
	return (0);
}
