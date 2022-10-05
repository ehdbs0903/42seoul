/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <daykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 16:43:37 by doykim            #+#    #+#             */
/*   Updated: 2022/09/29 19:46:59 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

void	print_error()
{
	printf("Error");
	exit(1);
}

int	check_argument(int ac, char **av)
{
	if (ac != 2)
		return (-1);
	if (ft_strnstr(av[1], ".ber", ft_strlen(av[1])))
		return (-1);
	return (0);
}

int	main(int ac, char **av)
{
	void *mlx_ptr;
	void *win_ptr;

	if (check_argument(ac, av) == -1)
		print_error();

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "mlx 42");
	mlx_loop(mlx_ptr);
	(void)win_ptr;
}
