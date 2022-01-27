/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 12:29:07 by doykim            #+#    #+#             */
/*   Updated: 2022/01/16 13:01:40 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_hex_addr(long long addr, unsigned int size)
{
	char			*hex;
	char			arr[16];
	unsigned int	i;
	unsigned int	len;

	hex = "0123456789abcdef";
	i = 0;
	len = 0;
	while (len < 16)
		arr[len++] = '0';
	while (i < size)
	{
		arr[i++] = hex[addr % 16];
		addr /= 16;
	}
	while (len-- > 0)
		write(1, &arr[len], 1);
}

void	ft_print_hex_str(char *str, unsigned int size)
{
	char			*hex;
	char			*cp_str;
	unsigned int	sz;

	hex = "0123456789abcdef";
	cp_str = str;
	sz = 0;
	while (sz < 16)
	{
		if (sz < size)
		{
			write(1, &hex[(unsigned char)*cp_str / 16], 1);
			write(1, &hex[(unsigned char)*cp_str++ % 16], 1);
		}
		else
		{
			write(1, " ", 1);
			write(1, " ", 1);
		}
		sz++;
		if (sz % 2 == 0)
			write(1, " ", 1);
	}
}

void	ft_print_str(char *str, unsigned int size)
{
	unsigned int	sz;

	sz = 0;
	while (sz++ < size)
	{
		if (*str < 32 || *str == 127)
		{
			write(1, ".", 1);
			str++;
		}
		else
			write(1, str++, 1);
	}
	write(1, "\n", 1);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	long long		int_addr;
	void			*addr_cp;
	unsigned int	sz;
	unsigned int	size_cp;

	size_cp = size;
	addr_cp = addr;
	sz = 0;
	while (sz < size / 16)
	{
		int_addr = (long long)addr_cp;
		ft_print_hex_addr(int_addr, 16);
		write(1, ": ", 2);
		ft_print_hex_str(addr_cp, 16);
		ft_print_str(addr_cp, 16);
		sz++;
		addr_cp += 16;
	}
	size %= 16;
	int_addr = (long long)addr_cp;
	ft_print_hex_addr(int_addr, 16);
	write(1, ": ", 2);
	ft_print_hex_str(addr_cp, size);
	ft_print_str(addr_cp, size);
	return (addr);
}
