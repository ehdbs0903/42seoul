/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 20:40:50 by doykim            #+#    #+#             */
/*   Updated: 2022/01/27 10:36:27 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	calculator(char **argv);

int	valid_operator(char *op)
{
	int	len;

	len = 0;
	while (op[len])
		len++;
	if (len != 1)
		return (1);
	if (op[0] != '+' && op[0] != '-' && op[0] != '*'
		&& op[0] != '/' && op[0] != '%')
		return (1);
	return (0);
}

int	valid_argc(int argc)
{
	if (argc != 4)
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	if (valid_argc(argc))
		return (0);
	if (valid_operator(argv[2]))
	{
		write(1, "0\n", 2);
		return (0);
	}
	calculator(argv);
	return (0);
}
