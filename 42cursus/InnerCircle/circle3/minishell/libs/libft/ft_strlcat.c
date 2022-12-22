/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungchoi <jungchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 16:31:41 by jungchoi          #+#    #+#             */
/*   Updated: 2022/03/24 15:11:47 by jungchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	dest_size;
	size_t	src_size;
	size_t	ret;

	i = 0;
	ret = 0;
	src_size = ft_strlen(src);
	dest_size = ft_strlen(dest);
	while (dest[ret] && ret < size)
		ret++;
	if (ret == size)
		return (size + src_size);
	if (dest_size < size)
	{
		while (src[i] != '\0' && dest_size + i + 1 < size)
		{
			dest[dest_size + i] = src[i];
			i++;
		}
	}
	dest[dest_size + i] = '\0';
	return (ret + src_size);
}
