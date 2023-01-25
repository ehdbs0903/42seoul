/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 04:32:01 by sanghan           #+#    #+#             */
/*   Updated: 2022/05/20 16:09:45 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char				*str;
	long unsigned int	str_len;

	if (s1 == NULL || set == NULL)
		return (NULL);
	str_len = ft_strlen(s1);
	while (str_len > 0)
	{
		if (ft_strchr(set, s1[str_len - 1]))
			str_len--;
		else if (ft_strchr(set, *s1))
		{
			str_len--;
			s1++;
		}
		else
			break ;
	}
	str = (char *)malloc(sizeof(char) * (str_len + 1));
	if (str == NULL)
		return (NULL);
	str[str_len] = '\0';
	while (str_len-- > 0)
		str[str_len] = s1[str_len];
	return (str);
}
