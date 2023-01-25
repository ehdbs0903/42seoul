/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 04:22:34 by sanghan           #+#    #+#             */
/*   Updated: 2022/05/20 14:20:35 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	mem;
	void	*p;

	mem = count * size;
	if (size != 0 && count * size / size != count)
		return (NULL);
	p = malloc(mem);
	if (p == NULL)
		return (NULL);
	ft_bzero(p, mem);
	return (p);
}
