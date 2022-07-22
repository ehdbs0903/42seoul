/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 17:03:32 by doykim            #+#    #+#             */
/*   Updated: 2022/07/22 16:54:18 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	parse_format(ap, char *format)
{
	if (*format == 'c')
		return write(1, &va_arg(ap, int), 1);
	else if (*format == 's')
		return print_s(va_arg(ap, char *));
	else if (*format == 'p')
		return print_p(va_arg(ap, void *));
	else if (*format == 'd' || *format == 'i')
		return print_di(va_arg(ap, int));
	else if (*format == 'u')
		return print_u(va_arg(ap, unsigned int));
	else if (*format == 'x' || *format == 'X')
		return print_x(va_arg(ap, unsigned int))
	else if (*format == '%')
		return write(1, "%", 1);
	else
		return (-1)
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		len;

	len = 0;
	va_start(ap, format);
	while (*format != '\0')
	{
		if (*format != '%')
			len += write(1, *format++, 1);
		else
			len += parse_format(ap, (char *)format);
	}
	va_end(ap);
	if (len < 0)
		return (-1);
	return (ret);
}
