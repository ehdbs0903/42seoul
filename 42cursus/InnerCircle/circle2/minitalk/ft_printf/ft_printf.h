/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 17:05:11 by doykim            #+#    #+#             */
/*   Updated: 2022/08/15 20:26:06 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

int		ft_printf(const char *format, ...);
int		ft_parse_format(va_list *ap, char format);
int		ft_print_c(char c);
int		ft_print_s(char *s);
int		ft_print_di(int n);
int		ft_print_p(unsigned long long ptr);
int		ft_print_u(unsigned int n);
int		ft_print_x(unsigned int num, char format);
void	ft_putstr(char *str);
void	ft_put_ptr(uintptr_t num);
int		ft_ptr_len(uintptr_t num);
char	*ft_uitoa(unsigned int n);
int		ft_num_len(unsigned	int num);
void	ft_put_hex(unsigned int num, char format);
int		ft_hex_len(unsigned	int num);

#endif
