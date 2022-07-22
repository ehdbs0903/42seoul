/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 14:12:29 by doykim            #+#    #+#             */
/*   Updated: 2022/05/10 16:11:08 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_startcheck(void)
{
	char	*rtv;

	rtv = malloc(sizeof(char));
	if (!rtv)
		return (NULL);
	rtv[0] = '\0';
	return (rtv);
}

static int	lencheck(char const *s, unsigned int start, size_t len)
{
	if ((ft_strlen(s) - start) < len)
		return ((ft_strlen(s) - start));
	else
		return (len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*sub;

	if (!s)
		return (0);
	i = 0;
	j = 0;
	if (ft_strlen(s) < start)
		return (ft_startcheck());
	sub = (char *)malloc(sizeof(char) * (lencheck(s, start, len) + 1));
	if (!sub)
		return (NULL);
	while (s[i])
	{
		if (i >= start && j < len)
		{
			sub[j] = s[i];
			j++;
		}
		i++;
	}
	sub[j] = '\0';
	return (sub);
}
