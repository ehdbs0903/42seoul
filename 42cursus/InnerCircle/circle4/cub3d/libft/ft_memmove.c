/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 04:20:07 by sanghan           #+#    #+#             */
/*   Updated: 2022/05/18 20:58:41 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*new_dst;
	unsigned char	*new_src;
	size_t			i;

	if (dst == src || len == 0)
		return (dst);
	new_dst = (unsigned char *)dst;
	new_src = (unsigned char *)src;
	i = 0;
	if (dst < src)
	{
		while (i++ < len)
			new_dst[i - 1] = new_src[i - 1];
	}
	else
	{
		while (i < len)
		{
			new_dst[len - 1 - i] = new_src[len - 1 - i];
			i++;
		}
	}
	return (dst);
}
