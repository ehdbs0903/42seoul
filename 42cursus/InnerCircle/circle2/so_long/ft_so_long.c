/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <daykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 16:43:37 by doykim            #+#    #+#             */
/*   Updated: 2022/10/05 21:27:28 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

void	print_error()
{
	ft_printf("Error");
	exit(1);
}

int	check_argument(int ac, char **av)
{
	int	i;

	if (ac != 2)
		return (-1);
	i = ft_strlen(av[1]) - 4;
	if (i <= 0)
		return (-1);
	if (!ft_strnstr(av[1] + i, ".ber", 4))
		return (-1);
	return (0);
}

void	init_game(t_game *game)
{
	game->width = 0;
	game->height = 0;
}

int	main(int ac, char **av)
{
	t_game	game;
	
	if (check_argument(ac, av) == -1)
		print_error();
	init_game(&game);
	game.mlx = mlx_init();
	read_map(av[1], &game);
	game.win = mlx_new_window(game.mlx, game.width * 64, game.height * 64, "mlx 42");
	init_img(&game);
	set_img(&game);
	mlx_loop(game.mlx);	
	return (0);
}
