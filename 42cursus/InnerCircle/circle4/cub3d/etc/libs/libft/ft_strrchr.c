/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungchoi <jungchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 21:16:22 by jungchoi          #+#    #+#             */
/*   Updated: 2022/03/28 16:32:10 by jungchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	size_t	len;
	char	*s_ptr;
	char	*last_address;

	i = 0;
	s_ptr = (char *)s;
	last_address = NULL;
	len = ft_strlen(s);
	while (i <= len)
	{
		if (s_ptr[i] == (char)c)
			last_address = &s_ptr[i];
		i++;
	}
	return (last_address);
}
