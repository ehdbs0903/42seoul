/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 18:41:57 by doykim            #+#    #+#             */
/*   Updated: 2022/01/25 08:58:41 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strcat(char *dest, char *src)
{
	int	idx;
	int	len1;
	int	len2;

	idx = 0;
	len1 = 0;
	len2 = 0;
	while (dest[len1] != '\0')
		len1++;
	while (src[len2] != '\0')
		len2++;
	while (idx < len2)
		dest[len1++] = src[idx++];
	dest[len1] = '\0';
	return (dest);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_strlen(int size, char **strs, char *sep)
{
	int	i;
	int	j;
	int	sum;
	int	sep_len;

	sep_len = 0;
	sum = 0;
	i = 0;
	j = 0;
	while (sep[sep_len])
		sep_len++;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
		{
			sum++;
			j++;
		}
		i++;
	}
	sum += sep_len * (size - 1);
	return (sum);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		len;
	char	*s;

	if (size == 0)
	{
		s = (char *)malloc(sizeof (char) * 1);
		return (s);
	}
	i = 1;
	len = ft_strlen(size, strs, sep);
	s = (char *)malloc(sizeof (char) * len + 1);
	s = ft_strcpy(s, strs[0]);
	while (i < size)
	{
		s = ft_strcat(s, sep);
		s = ft_strcat(s, strs[i]);
		i++;
	}
	s[len] = '\0';
	return (s);
}
