/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:40:49 by doykim            #+#    #+#             */
/*   Updated: 2023/02/08 20:43:33 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	on_click(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}

int	main(int ac, char *av[])
{
	t_game	game;
	t_img	img;

	init_game(ac, av, &game, &img);
	game.image->img = mlx_new_image(game.mlx, WIDTH, HEIGHT);
	if (game.image->img == NULL)
		exit(1);
	mlx_hook(game.win, 2, 0, key_press, &game);
	mlx_hook(game.win, 17, 0, on_click, &game);
	raycasting(&game);
	mlx_loop(game.mlx);
	return (0);
}
