/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 17:03:32 by doykim            #+#    #+#             */
/*   Updated: 2022/07/22 13:00:13 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		len;

	len = 0;
	va_start(ap, format);
	while (*format != '\0')
	{
		if (*format != '%')
			len += ft_putchar_fd(*format++, 1);
		else
			len += parse_format(ap, (char *)format);
	}
	va_end(ap);
	if (len < 0)
		return (-1);
	return (ret);
}
