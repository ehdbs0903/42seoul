/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 17:03:32 by doykim            #+#    #+#             */
/*   Updated: 2022/08/15 18:47:23 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_parse_format(va_list ap, char *format)
{
	if (*format == 'c')
		return ft_print_c(va_arg(ap, int));
	else if (*format == 's')
		return ft_print_s(va_arg(ap, char *));
	else if (*format == 'p')
		return ft_print_p(va_arg(ap, unsigned long long));
	else if (*format == 'd' || *format == 'i')
		return ft_print_di(va_arg(ap, int));
	else if (*format == 'u')
		return ft_print_u(va_arg(ap, unsigned int));
	else if (*format == 'x' || *format == 'X')
		return ft_print_x(va_arg(ap, unsigned int), *format);
	else if (*format == '%')
		return write(1, "%", 1);
	else
		return (-1);
}

int	ft_printf(char *format, ...)
{
	va_list	ap;
	int		len;

	len = 0;
	va_start(ap, format);
	while (*format != '\0')
	{
		if (*format != '%')
			len += write(1, format++, 1);
		else
			len += ft_parse_format(ap, (char *)format);
	}
	va_end(ap);
	if (len < 0)
		return (-1);
	return (len);
}
