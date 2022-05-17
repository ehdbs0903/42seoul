/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 14:01:55 by doykim            #+#    #+#             */
/*   Updated: 2022/01/26 14:02:02 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	search_charset(char	si, char	*charset)
{
	int	i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (si == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	get_arr_size(char	*str, char	*charset)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	if (str[0] == '\0')
		return (0);
	while (search_charset(str[i], charset))
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i + 1] != '\0')
	{
		if (!search_charset(str[i], charset)
			&& search_charset(str[i + 1], charset))
			cnt++;
		i++;
	}
	if (!search_charset(str[i], charset))
		cnt++;
	return (cnt);
}

int	get_str_size(int	*i, char	*str, char	*charset)
{
	int	m;

	while (search_charset(str[(*i)], charset))
		(*i)++;
	m = (*i);
	while (str[m] != '\0' && !search_charset(str[m], charset))
		m++;
	return (m - (*i));
}

char	*ft_strncpy(char	*dest, char	*src, int	i, int	str_size)
{
	int	m;
	int	j;

	j = 0;
	m = i;
	while (i < m + str_size && src[i] != '\0')
	{
		dest[j] = src[i];
		i++;
		j++;
	}
	while (i < m + str_size)
	{
		dest[j] = '\0';
		i++;
		j++;
	}
	return (dest);
}

char	**ft_split(char	*str, char	*charset)
{
	char	**ret;
	int		arr_size;
	int		str_size;
	int		i;
	int		j;

	i = 0;
	j = 0;
	arr_size = get_arr_size(str, charset);
	ret = (char **)malloc(sizeof(char *) * (arr_size + 1));
	ret[arr_size] = NULL;
	while (arr_size--)
	{
		while (search_charset(str[i], charset))
			i++;
		str_size = get_str_size(&i, str, charset);
		if (str_size != 0)
		{
			ret[j] = (char *)malloc(sizeof(char) * (str_size + 1));
			ret[j] = ft_strncpy(ret[j], str, i, str_size);
			ret[j++][str_size] = '\0';
			i = i + str_size;
		}
	}
	return (ret);
}
