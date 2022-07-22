/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 15:55:22 by doykim            #+#    #+#             */
/*   Updated: 2022/07/22 16:54:56 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_s(char *s)
{
	ft_putstr_fd(s, 1);
	return ft_strlen(s);
}

int print_p(unsigned int)
{
	
}

int	print_di(int n)
{
	print_s(ft_itoa(n));	
}

int	print_u(unsigned int n)
{

}

int print_x(unsigned int n)
{

}

