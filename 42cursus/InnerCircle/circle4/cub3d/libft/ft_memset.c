/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 04:47:44 by sanghan           #+#    #+#             */
/*   Updated: 2022/05/18 19:59:32 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*new_dest;
	size_t			i;

	new_dest = b;
	i = 0;
	while (i < len)
	{
		new_dest[i] = c;
		i++;
	}
	return (b);
}
