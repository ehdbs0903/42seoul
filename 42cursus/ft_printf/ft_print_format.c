/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 15:55:22 by doykim            #+#    #+#             */
/*   Updated: 2022/08/15 18:50:31 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_c(char c)
{
	return write(1, &c, 1);
}

int	ft_print_s(char *s)
{
	ft_putstr_fd(s, 1);
	return ft_strlen(s);
}

int	ft_print_di(int n)
{
	return ft_print_s(ft_itoa(n));	
}
