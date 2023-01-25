/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungchoi <jungchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 21:26:46 by jungchoi          #+#    #+#             */
/*   Updated: 2022/03/24 13:03:20 by jungchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	check_find(char *ret, const char *needle, size_t len, size_t i)
{
	size_t	temp;

	temp = 0;
	while (needle[temp] && ret[i + temp] && i + temp < len)
	{
		if ((needle[temp] != ret[i + temp]))
			break ;
		temp++;
	}
	return (temp);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	temp;
	char	*ret;

	ret = (char *)haystack;
	if (ft_strlen(needle) == 0)
		return (ret);
	if (len == 0)
		return (0);
	i = 0;
	while (i < len && ret[i])
	{
		if (needle[0] == ret[i])
		{
			temp = check_find(ret, needle, len, i);
			if (needle[temp] == '\0')
				return (&ret[i]);
		}
		i++;
	}
	return (0);
}
