/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 04:18:57 by sanghan           #+#    #+#             */
/*   Updated: 2022/05/20 13:10:26 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*new_dest;
	size_t			i;

	new_dest = s;
	i = 0;
	while (i < n)
	{
		new_dest[i] = 0;
		i++;
	}
}
