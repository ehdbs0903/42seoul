/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungchoi <jungchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 20:29:09 by jungchoi          #+#    #+#             */
/*   Updated: 2022/03/25 15:39:54 by jungchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	size_t	len;
	char	*ret;

	ret = (char *)s;
	i = 0;
	len = ft_strlen(s);
	while (i <= len)
	{
		if (ret[i] == (char)c)
			return (ret + i);
		i++;
	}
	return (0);
}
