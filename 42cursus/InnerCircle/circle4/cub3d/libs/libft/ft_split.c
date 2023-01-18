/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungchoi <jungchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 19:05:36 by jungchoi          #+#    #+#             */
/*   Updated: 2022/03/24 13:05:28 by jungchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strndup(char const *s, int n)
{
	int		i;
	char	*dest;

	dest = (char *)malloc(sizeof(char) * (n + 1));
	if (!dest)
		return (0);
	i = 0;
	while (i < n && s[i])
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static int	ft_free(char **ret, int j)
{
	while (--j >= 0)
	{
		free(ret[j]);
		ret[j] = 0;
	}
	free(ret);
	ret = 0;
	return (0);
}

static int	ft_putarr(char **ret, char const *s, char c, int j)
{
	int	i;
	int	start;
	int	len;

	i = 0;
	while (s[i] == c)
		i++;
	start = i;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
		{
			len = i - start + 1;
			ret[j++] = ft_strndup(&s[start], len);
			if (ret[j - 1] == 0)
				return (ft_free(ret, j - 1));
		}
		else if (s[i] == c && s[i + 1] != c)
			start = i + 1;
		i++;
	}
	ret[j] = 0;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		word;
	char	**ret;

	i = 0;
	word = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			word++;
		i++;
	}
	ret = (char **)malloc(sizeof(char *) * (word + 1));
	if (!ret)
		return (0);
	if (s[0])
	{
		if (ft_putarr(ret, s, c, 0) == 0)
			return (0);
	}
	else
		ret[0] = 0;
	return (ret);
}
